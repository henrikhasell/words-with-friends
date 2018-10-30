#ifndef GRID_HPP
#define GRID_HPP

#include <map>
#include <set>
#include <string>
#include <vector>
#include "trie.hpp"

extern std::map<char, int> charScores;
extern Trie validWords;

class Grid
{
public:
    struct Anchor
    {
        Anchor(size_t x, size_t y, bool horizontal) :
            x(x),
            y(y),
            horizontal(horizontal)
        {}

        size_t x;
        size_t y;
        bool horizontal;
    };
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
        bool cross_check;
        char value;
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
    void fetch(size_t x, size_t y, bool horizontal, std::string &word);
    bool check(size_t x, size_t y, bool horizontal);
    void calculateAnchors(std::vector<Anchor> &anchors);
    void calculateBestMove(std::string characters);
    bool validateWords(bool horizontal);
    bool validateWords();
    bool validateLattice() const;
    bool validate();
    int score();

    size_t w; // Should be private.
    size_t h; // Should be private.
private:
    Tile *tiles;
};

#endif
