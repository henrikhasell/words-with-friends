#ifndef GRID_HPP
#define GRID_HPP

#include <map>
#include <set>
#include <string>

extern std::map<char, int> charScores;
extern std::set<std::string> validWords;

class Grid
{
public:
	struct Tile
	{
		enum Type
		{
			Normal,
			DoubleLetter,
			DoubleWord,
			TrippleLetter,
			TrippleWord,
			Start
		};
		Tile();
		char value;
		bool bonus;// Should multipliers be applied in scoring.
		Type type;
	};

	static Grid Large();
	static Grid Small();

	Grid(size_t w, size_t h);
	Grid(const Grid &grid);
	~Grid();
	Grid &operator=(const Grid &grid);

	Tile *getTile(size_t x, size_t y);
	void insert(size_t x, size_t y, bool horizontal, std::string word);
	void calculateBestMove(std::string characters);
	bool validateWords(bool horizontal);
	bool validateWords();
	bool validateLattice();
	bool validate();
	int score();

	size_t w; // Should be private.
	size_t h;// Should be private.
	std::string message;// Should be private.
private:
	Tile *tiles;
};

#endif