#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "grid.hpp"

#define TILE_SIZE 32
#define GLYPH_W 8
#define GLYPH_H 8
#define GRID_SIZE_X 11
#define GRID_SIZE_Y 11

std::map<char, int> charScores;
std::set<std::string> validWords;
std::string available;

static SDL_Rect src_rect;
static SDL_Rect dst_rect;

enum InputMode
{
	Board, Available
};

static InputMode input_mode = Board;

void render_glyph(
	SDL_Surface *dst_surface,
	SDL_Surface *src_surface,
	int x, int y,
	unsigned char value)
{
	src_rect.x = GLYPH_W * (value % 16);
	src_rect.y = GLYPH_H * (value / 16);
	src_rect.w = GLYPH_W;
	src_rect.h = GLYPH_H;

	dst_rect.x = TILE_SIZE * x;
	dst_rect.y = TILE_SIZE * y;
	dst_rect.w = TILE_SIZE;
	dst_rect.h = TILE_SIZE;

	SDL_BlitScaled(
		src_surface, &src_rect, dst_surface, &dst_rect);
}

void load_words(const char path[])
{
	std::ifstream file;
	file.open(path);

	std::string word;
	while(file >> word)
	{
		for(char &i : word) i = toupper(i);
		validWords.insert(word);
	}
}

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		SDL_Window *window = SDL_CreateWindow(
			"Word Game",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			TILE_SIZE * GRID_SIZE_X,
			TILE_SIZE * (GRID_SIZE_Y + 1),
			0);
		if(window)
		{
			charScores['A'] = 1;
			charScores['B'] = 4;
			charScores['C'] = 4;
			charScores['D'] = 2;
			charScores['E'] = 1;
			charScores['F'] = 4;
			charScores['G'] = 3;
			charScores['H'] = 3;
			charScores['I'] = 1;
			charScores['J'] = 10;
			charScores['K'] = 5;
			charScores['L'] = 2;
			charScores['M'] = 4;
			charScores['N'] = 2;
			charScores['O'] = 1;
			charScores['P'] = 4;
			charScores['Q'] = 10;
			charScores['R'] = 1;
			charScores['S'] = 1;
			charScores['T'] = 1;
			charScores['U'] = 2;
			charScores['V'] = 5;
			charScores['W'] = 4;
			charScores['X'] = 8;
			charScores['Y'] = 3;
			charScores['Z'] = 10;

			Grid grid = Grid::Small();

			load_words("dictionary.txt");
			SDL_Surface *window_surface = SDL_GetWindowSurface(window);
			SDL_Surface *text_surface = SDL_LoadBMP("Text.bmp");
			SDL_SetColorKey(text_surface, SDL_TRUE, 0x000000);
			bool finished = false;
			int cursor_x = 0;
			int cursor_y = 0;
			while(!finished)
			{
				for(int x = 0; x < grid.w; x++)
				{
					for(int y = 0; y < grid.h; y++)
					{
						const Grid::Tile *tile = grid.getTile(x, y);

						dst_rect.x = x * TILE_SIZE;
						dst_rect.y = y * TILE_SIZE;
						dst_rect.w = TILE_SIZE;
						dst_rect.h = TILE_SIZE;

						Uint32 colour;

						if(tile->value != ' ')
						{
							colour = 0xf0b432;
						}
						else
						{
							switch(tile->type)
							{
							case Grid::Tile::Normal:
								colour = 0xdee4ea; break;
							case Grid::Tile::DoubleWord:
								colour = 0xb3554d; break;
							case Grid::Tile::DoubleLetter:
								colour = 0x1181be; break;
							case Grid::Tile::TrippleWord:
								colour = 0xea9932; break;
							case Grid::Tile::TrippleLetter:
								colour = 0x6ea256; break;
							case Grid::Tile::Start:
								colour = 0x78569a; break;
							}
						}
						SDL_FillRect(window_surface, &dst_rect, colour);
						if(tile->value != ' ')
						{
							render_glyph(
								window_surface, text_surface, x, y, tile->value);
						}
					}
				}

				dst_rect.x = 0;
				dst_rect.y = TILE_SIZE * GRID_SIZE_Y;
				dst_rect.w = TILE_SIZE * 11;
				dst_rect.h = TILE_SIZE;

				SDL_FillRect(window_surface, &dst_rect, 0x000000);

				if(input_mode == Board)
				{
					render_glyph(
						window_surface, text_surface,
						cursor_x,
						cursor_y, 224);
				}
				else
				{
					render_glyph(
						window_surface, text_surface,
						(int)available.length(),
						(int)GRID_SIZE_Y, 224);
				}

				for(int i = 0; i < available.length(); i++)
				{
					render_glyph(
						window_surface, text_surface, i,
						GRID_SIZE_Y, available[i]);
				}

				SDL_UpdateWindowSurface(window);

				SDL_Event e;
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						finished = true;
						break;
					}
					else if(e.type == SDL_TEXTINPUT)
					{
						if(input_mode == Board)
						{
							Grid::Tile *selected =
								grid.getTile(cursor_x, cursor_y);
							selected->value = e.text.text[0];
							selected->bonus = true;
						}
						else
						{
							available += e.text.text;
						}
					}
					else if(e.type == SDL_KEYDOWN)
					{
						switch(e.key.keysym.sym)
						{
						case SDLK_UP:
							if(input_mode == Board)
							{
								if(cursor_y > 0)
								{
									cursor_y--;
								}
							}
							else
							{
								input_mode = Board;
							}
							break;
						case SDLK_DOWN:
							if(input_mode == Board)
							{
								if(cursor_y < grid.h - 1)
								{
									cursor_y++;
								}
								else
								{
									input_mode = Available;
								}
							}
							break;
						case SDLK_LEFT:
							if(cursor_x > 0)
							{
								cursor_x--;
							}
							break;
						case SDLK_RIGHT:
							if(cursor_x < grid.w - 1)
							{
								cursor_x++;
							}
							break;
						case SDLK_RETURN:
							if(input_mode == Board)
							{
								grid.validate();
								std::cout << grid.message << std::endl;
							}
							else
							{
								grid.calculateBestMove(available);
								std::cout << "Done!" << std::endl;
							}
							break;
						case SDLK_BACKSPACE:
							if(available.length() > 0)
							{
								available.pop_back();
							}
							break;
						case SDLK_INSERT:
							grid.insert(cursor_x, cursor_y, false, available);
							break;
						}
					}
				}
			}
			SDL_FreeSurface(text_surface);
		}
		else
		{
			std::cout << "SDL_CreateWindow: " << SDL_GetError() << std::endl;
		}
		SDL_Quit();
	}
	return 0;
}