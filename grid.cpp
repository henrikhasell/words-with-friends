#include "grid.hpp"
#include "permutation.hpp"
#include <chrono>
#include <iostream>
#include <new>
#include <queue>

extern std::string message;

Grid::Tile::Tile() : value(' '), type(Tile::Normal)
{

}


Grid Grid::Large()
{
	Grid grid(15, 15);

	grid.getTile(3, 0)->type = Tile::TrippleWord;
	grid.getTile(6, 0)->type = Tile::TrippleLetter;
	grid.getTile(8, 0)->type = Tile::TrippleLetter;
	grid.getTile(11, 0)->type = Tile::TrippleWord;

	grid.getTile(2, 1)->type = Tile::DoubleLetter;
	grid.getTile(5, 1)->type = Tile::DoubleWord;
	grid.getTile(9, 1)->type = Tile::DoubleWord;
	grid.getTile(12, 1)->type = Tile::DoubleLetter;

	grid.getTile(1, 2)->type = Tile::DoubleLetter;
	grid.getTile(4, 2)->type = Tile::DoubleLetter;
	grid.getTile(10, 2)->type = Tile::DoubleLetter;
	grid.getTile(13, 2)->type = Tile::DoubleLetter;

	grid.getTile(0, 3)->type = Tile::TrippleWord;
	grid.getTile(3, 3)->type = Tile::TrippleLetter;
	grid.getTile(7, 3)->type = Tile::DoubleWord;
	grid.getTile(11, 3)->type = Tile::TrippleLetter;
	grid.getTile(14, 3)->type = Tile::TrippleWord;

	grid.getTile(2, 4)->type = Tile::DoubleLetter;
	grid.getTile(6, 4)->type = Tile::DoubleLetter;
	grid.getTile(8, 4)->type = Tile::DoubleLetter;
	grid.getTile(12, 4)->type = Tile::DoubleLetter;

	grid.getTile(1, 5)->type = Tile::DoubleWord;
	grid.getTile(5, 5)->type = Tile::TrippleLetter;
	grid.getTile(9, 5)->type = Tile::TrippleLetter;
	grid.getTile(13, 5)->type = Tile::DoubleWord;

	grid.getTile(0, 6)->type = Tile::TrippleLetter;
	grid.getTile(4, 6)->type = Tile::DoubleLetter;
	grid.getTile(10, 6)->type = Tile::DoubleLetter;
	grid.getTile(14, 6)->type = Tile::TrippleLetter;

	grid.getTile(3, 7)->type = Tile::DoubleWord;
	grid.getTile(7, 7)->type = Tile::Start;
	grid.getTile(11, 7)->type = Tile::DoubleWord;

	grid.getTile(0, 8)->type = Tile::TrippleLetter;
	grid.getTile(4, 8)->type = Tile::DoubleLetter;
	grid.getTile(10, 8)->type = Tile::DoubleLetter;
	grid.getTile(14, 8)->type = Tile::TrippleLetter;

	grid.getTile(1, 9)->type = Tile::DoubleWord;
	grid.getTile(5, 9)->type = Tile::TrippleLetter;
	grid.getTile(9, 9)->type = Tile::TrippleLetter;
	grid.getTile(13, 9)->type = Tile::DoubleWord;

	grid.getTile(2, 10)->type = Tile::DoubleLetter;
	grid.getTile(6, 10)->type = Tile::DoubleLetter;
	grid.getTile(8, 10)->type = Tile::DoubleLetter;
	grid.getTile(12, 10)->type = Tile::DoubleLetter;

	grid.getTile(0, 11)->type = Tile::TrippleWord;
	grid.getTile(3, 11)->type = Tile::TrippleLetter;
	grid.getTile(7, 11)->type = Tile::DoubleWord;
	grid.getTile(11, 11)->type = Tile::TrippleLetter;
	grid.getTile(14, 11)->type = Tile::TrippleWord;

	grid.getTile(1, 12)->type = Tile::DoubleLetter;
	grid.getTile(4, 12)->type = Tile::DoubleLetter;
	grid.getTile(10, 12)->type = Tile::DoubleLetter;
	grid.getTile(13, 12)->type = Tile::DoubleLetter;

	grid.getTile(2, 13)->type = Tile::DoubleLetter;
	grid.getTile(5, 13)->type = Tile::DoubleWord;
	grid.getTile(9, 13)->type = Tile::DoubleWord;
	grid.getTile(12, 13)->type = Tile::DoubleLetter;

	grid.getTile(3, 14)->type = Tile::TrippleWord;
	grid.getTile(6, 14)->type = Tile::TrippleLetter;
	grid.getTile(8, 14)->type = Tile::TrippleLetter;
	grid.getTile(11, 14)->type = Tile::TrippleWord;

	return grid;
}

Grid Grid::Small()
{
	Grid grid(11, 11);

	grid.getTile(0, 0)->type = Tile::TrippleLetter;
	grid.getTile(2, 0)->type = Tile::TrippleWord;
	grid.getTile(8, 0)->type = Tile::TrippleWord;
	grid.getTile(10, 0)->type = Tile::TrippleLetter;

	grid.getTile(1, 1)->type = Tile::DoubleWord;
	grid.getTile(5, 1)->type = Tile::DoubleWord;
	grid.getTile(9, 1)->type = Tile::DoubleWord;

	grid.getTile(0, 2)->type = Tile::TrippleWord;
	grid.getTile(2, 2)->type = Tile::TrippleLetter;
	grid.getTile(4, 2)->type = Tile::DoubleLetter;
	grid.getTile(6, 2)->type = Tile::DoubleLetter;
	grid.getTile(8, 2)->type = Tile::TrippleLetter;
	grid.getTile(10, 2)->type = Tile::TrippleWord;

	grid.getTile(3, 3)->type = Tile::TrippleLetter;
	grid.getTile(7, 3)->type = Tile::TrippleLetter;

	grid.getTile(2, 4)->type = Tile::DoubleLetter;
	grid.getTile(8, 4)->type = Tile::DoubleLetter;

	grid.getTile(1, 5)->type = Tile::DoubleWord;
	grid.getTile(5, 5)->type = Tile::Start;
	grid.getTile(9, 5)->type = Tile::DoubleWord;

	grid.getTile(2, 6)->type = Tile::DoubleLetter;
	grid.getTile(8, 6)->type = Tile::DoubleLetter;

	grid.getTile(3, 7)->type = Tile::TrippleLetter;
	grid.getTile(7, 7)->type = Tile::TrippleLetter;

	grid.getTile(0, 8)->type = Tile::TrippleWord;
	grid.getTile(2, 8)->type = Tile::TrippleLetter;
	grid.getTile(4, 8)->type = Tile::DoubleLetter;
	grid.getTile(6, 8)->type = Tile::DoubleLetter;
	grid.getTile(8, 8)->type = Tile::TrippleLetter;
	grid.getTile(10, 8)->type = Tile::TrippleWord;

	grid.getTile(1, 9)->type = Tile::DoubleWord;
	grid.getTile(5, 9)->type = Tile::DoubleWord;
	grid.getTile(9, 9)->type = Tile::DoubleWord;

	grid.getTile(0, 10)->type = Tile::TrippleLetter;
	grid.getTile(2, 10)->type = Tile::TrippleWord;
	grid.getTile(8, 10)->type = Tile::TrippleWord;
	grid.getTile(10, 10)->type = Tile::TrippleLetter;

	return grid;
}

Grid::Grid(size_t w, size_t h) : w(w), h(h)
{
	tiles = new Tile[w * h];
}

Grid::Grid(const Grid &grid) : Grid(grid.w, grid.h)
{
	for(size_t i = 0; i < w * h; i++)
	{
		tiles[i] = grid.tiles[i];
	}
}

Grid::~Grid()
{
	delete[] tiles;
}

Grid &Grid::operator=(const Grid &grid)
{
	delete[] tiles;
	w = grid.w;
	h = grid.h;
	tiles = new Tile[w * h];
	for(size_t i = 0; i < w * h; i++)
	{
		tiles[i] = grid.tiles[i];
	}
	return *this;
}

Grid::Tile *Grid::getTile(size_t x, size_t y)
{
	return tiles + x + w * y;
}


void Grid::insert(size_t x, size_t y, bool horizontal, std::string word)
{
	size_t *i;
	size_t i_max;

	if(horizontal)
	{
		i = &x;
		i_max = w;
	}
	else
	{
		i = &y;
		i_max = h;
	}

	size_t index = 0;

	while(*i < i_max)
	{
		if(word.length() == index)
		{
			break;
		}

		Tile *tile = getTile(x, y);

		if(tile->value == ' ')
		{
			tile->value = word[index++];
		}

		i[0]++;
	}
}

void Grid::fetch(size_t x, size_t y, bool horizontal, std::string &word)
{
	size_t *i;
	size_t i_max;

	if(horizontal)
	{
		i = &x;
		i_max = w;
	}
	else
	{
		i = &y;
		i_max = h;
	}

	while(*i > 0)
	{
		i[0]--;

		Tile *tile = getTile(x, y);

		if(tile->value == ' ')
		{
			i[0]++;
			break;
		}
	}

	while(*i < i_max)
	{
		Tile *tile = getTile(x, y);

		if(tile->value == ' ')
		{
			break;
		}
		word += tile->value;
		i[0]++;
	}
}

void Grid::calculateBestMove(std::string available)
{
	Grid best = *this;

	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point t2;

	int best_score = this->score();

    for(const bool orientation : { true, false })
    {
        for(size_t x = 0; x < w; x++)
        {
            for(size_t y = 0; y < h; y++)
            {
                Permutation permutation(available, x, y, orientation, *this);

                for(const std::string &result : permutation.results)
                {
                    Grid copy = *this;
                    copy.insert(x, y, orientation, result);
                    if(copy.validate())
                    {
                        int copy_score = copy.score();

                        if(copy_score > best_score)
                        {
                            best_score = copy_score;
                            best = copy;
                        }
                    }
                }
            }
        }
    }

	t2 = std::chrono::steady_clock::now();

	std::chrono::duration<double> timeElapsedDuration =
		std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

	std::cout << "Time elapsed: " << timeElapsedDuration.count() << " seconds." << std::endl;
	std::cout << "Best score: " << (best_score - this->score()) << std::endl;
	message = "Done!";

	*this = best;
}

bool Grid::validateWords(bool horizontal)
{
	size_t i;
	size_t j;

	size_t i_max;
	size_t j_max;

	size_t *x;
	size_t *y;

	if(horizontal)
	{
		i_max = h;
		j_max = w;

		x = &j;
		y = &i;
	}
	else
	{
		i_max = w;
		j_max = h;

		x = &i;
		y = &j;
	}

	std::string word;

	for(i = 0; i < i_max; i++)
	{
		for(j = 0; j < j_max; j++)
		{
			Tile *tile = getTile(*x, *y);

			if(tile->value != ' ')
			{
				word += tile->value;
			}
			if(tile->value == ' ' || j == j_max - 1)
			{
				if(word.length() > 1)
				{
					for(char &i : word)
					{
						i = tolower(i);
					}
					bool valid;
					if(!validWords.contains(word, &valid) || !valid)
					{
						message = "Invalid word: " + word;
						return false;
					}
				}
				word.clear();
			}
		}
	}

	return true;
}

bool Grid::validateWords()
{
	return validateWords(true) && validateWords(false);
}

bool Grid::validateLattice() const
{
	Grid copy = *this;

	std::queue<std::tuple<size_t, size_t>> open_set;
	open_set.emplace(w / 2, h / 2);

	while(!open_set.empty())
	{
		std::tuple<size_t, size_t> &head =
			open_set.front();

		const size_t x = std::get<0>(head);
		const size_t y = std::get<1>(head);

		Tile *tile = copy.getTile(x, y);

		if(tile->value != ' ')
		{

			if(x > 0)
			{
				open_set.emplace(x - 1, y);
			}
			if(y > 0)
			{
				open_set.emplace(x, y - 1);
			}
			if(x < w - 1)
			{
				open_set.emplace(x + 1, y);
			}
			if(y < h  - 1)
			{
				open_set.emplace(x, y + 1);
			}

			tile->value = ' ';
		}

		open_set.pop();
	}

	for(size_t i = 0; i < copy.w * copy.h; i++)
	{
		if(copy.tiles[i].value != ' ')
		{
			message = "Invalid lattice.";
			return false;
		}
	}

	return true;
}

bool Grid::validate()
{
	bool result = validateLattice() && validateWords();

	if(result)
	{
		message = "Validation successfull.";
	}

	return result;
}

int Grid::score()
{
	int total = 0;

	for(const bool horizontal : {true, false})
	{
		size_t i;
		size_t j;

		size_t i_max;
		size_t j_max;

		size_t *x;
		size_t *y;

		std::vector<Tile*> word;

		if(horizontal)
		{
			i_max = h;
			j_max = w;

			x = &j;
			y = &i;
		}
		else
		{
			i_max = w;
			j_max = h;

			x = &i;
			y = &j;
		}

		for(i = 0; i < i_max; i++)
		{
			for(j = 0; j < j_max; j++)
			{
				Tile *tile = getTile(*x, *y);

				if(tile->value != ' ')
				{
					word.push_back(tile);
				}
				if(tile->value == ' ' || j == j_max - 1)
				{
					if(word.size() > 1)
					{
						int word_multiplier = 1;

						for(Tile *tile : word)
						{
							switch(tile->type)
							{
							case Tile::DoubleWord:
								word_multiplier *= 2; break;
							case Tile::TrippleWord:
								word_multiplier *= 3; break;
							}
						}

						for(Tile *tile : word)
						{
							int tile_multiplier = 1;

							switch(tile->type)
							{
							case Tile::DoubleLetter:
								tile_multiplier = 2; break;
							case Tile::TrippleLetter:
								tile_multiplier = 3; break;
							}

							total += charScores[toupper(tile->value)] * tile_multiplier * word_multiplier;
						}
					}
					word.clear();
				}
			}
		}
	}
	return total;
}
