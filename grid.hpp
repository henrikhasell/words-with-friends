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

        // There has got to be a better way!
        // https://stackoverflow.com/questions/32218118/c-std-set-insert-not-working

        bool operator<(const Placement &right) const
        {
            if(score <= right.score)
            {
                if(score < right.score)
                    return true;

                if(horizontal <= right.horizontal)
                {
                    if(horizontal < right.horizontal)
                        return true;

                    if(word <= right.word)
                    {
                        if(word < right.word || x + 256 * y < right.x + 256 * right.y)
                            return true;
                    }
                }
            }

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
    Grid &operator=(const Grid &grid);

    Tile *getTile(size_t x, size_t y) const;
    void insert(size_t x, size_t y, bool horizontal, const std::string &word);

    // TODO
    void insertPermutation(
        size_t x,
        size_t y,
        bool horizontal,
        const std::string &permutation,
        std::set<Placement> &placements) const;

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
