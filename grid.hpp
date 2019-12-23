#ifndef GRID_HPP
#define GRID_HPP

#include <map>
#include <set>
#include <string>
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

        bool operator<(const Anchor &right) const {
            if(x < right.x) return true;
            if(x > right.x) return false;

            if(y < right.y) return true;
            if(y > right.y) return false;

            return horizontal < right.horizontal;
        }
        bool operator==(const Anchor &right) const {
            printf("Equality operator called.\n");
            return x == right.x && y == right.y && horizontal == right.horizontal;
        }
    };
    struct Placement
    {
        Placement(
            size_t x,
            size_t y,
            bool horizontal,
            const std::string &word,
            const std::string &letters,
            int score
        ) :
            x(x),
            y(y),
            horizontal(horizontal),
            word(word),
            letters(letters),
            score(score)
        {}

        bool operator<(const Placement &right) const
        {
            if(score < right.score) return true;
            if(score > right.score) return false;

            if(x < right.x) return true;
            if(x > right.x) return false;

            if(y < right.y) return true;
            if(y > right.y) return false;

            if(this->horizontal < right.horizontal) return true;

            if(word < right.word) return true;
            if(word > right.word) return false;

            return false;
        }

        const size_t x;
        const size_t y;
	const bool horizontal;
        const std::string word;
        const std::string letters;
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

    Tile *getTile(size_t x, size_t y) const;
    void insert(size_t x, size_t y, bool horizontal, const std::string &word);

    void fetch(size_t x, size_t y, bool horizontal, std::string &word) const;
    bool check(size_t x, size_t y, bool horizontal) const;
    std::set<Placement> calculatePlacements(std::string characters) const;
    void calculateBestMove(std::string characters);
    bool validate() const;
    int score(size_t x, size_t y, bool horizontal, bool recursive = true);

    size_t w; // Should be private.
    size_t h; // Should be private.
    void calculateAnchors(std::set<Anchor> &anchors) const;
protected:
    bool validateWords(bool horizontal) const;
    bool validateWords() const;
    bool validateLattice() const;
private:
    Tile *tiles;
};

#endif
