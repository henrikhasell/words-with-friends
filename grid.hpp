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
        const size_t x;
        const size_t y;
        const bool horizontal;
    };
    struct Placement
    {
        Placement(
            size_t x,
            size_t y,
            bool horizontal,
            const std::string &word,
            int score
        ) :
            x(x),
            y(y),
            horizontal(horizontal),
            word(word),
            score(score)
        {}

        bool operator<(const Placement &right) const
        {
            return score < right.score || (score == right.score && word < right.word);
        }

        const size_t x;
        const size_t y;
	const bool horizontal;
        const std::string word;
	const int score;
    };
    struct Tile
    {
        enum Type
        {
            Normal,
            DoubleLetter,
            DoubleWord,
            TripleLetter,
            TripleWord,
            Start
        };
        Tile();
        Type type;
        bool wild;
        bool cross_check;
        char value;
    };

    static Grid Large();
    static Grid Small();

    Grid(size_t w, size_t h);
    Grid(const Grid &grid);
    ~Grid();
    Grid &operator=(const Grid &grid);

    Tile *getTile(size_t x, size_t y) const;
    void insert(size_t x, size_t y, bool horizontal, std::string word);
    void fetch(size_t x, size_t y, bool horizontal, std::string &word) const;
    bool check(size_t x, size_t y, bool horizontal) const;
    std::set<Placement> calculatePlacements(std::string characters) const;
    void calculateBestMove(std::string characters);
    bool validate() const;
    int score(size_t x, size_t y, bool horizontal, bool recursive = true);

    size_t w; // Should be private.
    size_t h; // Should be private.
protected:
    bool validateWords(bool horizontal) const;
    bool validateWords() const;
    bool validateLattice() const;
    void calculateAnchors(std::vector<Anchor> &anchors) const;
private:
    Tile *tiles;
};

#endif
