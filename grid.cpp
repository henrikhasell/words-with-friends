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

    grid.getTile(3, 0)->type = Tile::TripleWord;
    grid.getTile(6, 0)->type = Tile::TripleLetter;
    grid.getTile(8, 0)->type = Tile::TripleLetter;
    grid.getTile(11, 0)->type = Tile::TripleWord;

    grid.getTile(2, 1)->type = Tile::DoubleLetter;
    grid.getTile(5, 1)->type = Tile::DoubleWord;
    grid.getTile(9, 1)->type = Tile::DoubleWord;
    grid.getTile(12, 1)->type = Tile::DoubleLetter;

    grid.getTile(1, 2)->type = Tile::DoubleLetter;
    grid.getTile(4, 2)->type = Tile::DoubleLetter;
    grid.getTile(10, 2)->type = Tile::DoubleLetter;
    grid.getTile(13, 2)->type = Tile::DoubleLetter;

    grid.getTile(0, 3)->type = Tile::TripleWord;
    grid.getTile(3, 3)->type = Tile::TripleLetter;
    grid.getTile(7, 3)->type = Tile::DoubleWord;
    grid.getTile(11, 3)->type = Tile::TripleLetter;
    grid.getTile(14, 3)->type = Tile::TripleWord;

    grid.getTile(2, 4)->type = Tile::DoubleLetter;
    grid.getTile(6, 4)->type = Tile::DoubleLetter;
    grid.getTile(8, 4)->type = Tile::DoubleLetter;
    grid.getTile(12, 4)->type = Tile::DoubleLetter;

    grid.getTile(1, 5)->type = Tile::DoubleWord;
    grid.getTile(5, 5)->type = Tile::TripleLetter;
    grid.getTile(9, 5)->type = Tile::TripleLetter;
    grid.getTile(13, 5)->type = Tile::DoubleWord;

    grid.getTile(0, 6)->type = Tile::TripleLetter;
    grid.getTile(4, 6)->type = Tile::DoubleLetter;
    grid.getTile(10, 6)->type = Tile::DoubleLetter;
    grid.getTile(14, 6)->type = Tile::TripleLetter;

    grid.getTile(3, 7)->type = Tile::DoubleWord;
    grid.getTile(7, 7)->type = Tile::Start;
    grid.getTile(11, 7)->type = Tile::DoubleWord;

    grid.getTile(0, 8)->type = Tile::TripleLetter;
    grid.getTile(4, 8)->type = Tile::DoubleLetter;
    grid.getTile(10, 8)->type = Tile::DoubleLetter;
    grid.getTile(14, 8)->type = Tile::TripleLetter;

    grid.getTile(1, 9)->type = Tile::DoubleWord;
    grid.getTile(5, 9)->type = Tile::TripleLetter;
    grid.getTile(9, 9)->type = Tile::TripleLetter;
    grid.getTile(13, 9)->type = Tile::DoubleWord;

    grid.getTile(2, 10)->type = Tile::DoubleLetter;
    grid.getTile(6, 10)->type = Tile::DoubleLetter;
    grid.getTile(8, 10)->type = Tile::DoubleLetter;
    grid.getTile(12, 10)->type = Tile::DoubleLetter;

    grid.getTile(0, 11)->type = Tile::TripleWord;
    grid.getTile(3, 11)->type = Tile::TripleLetter;
    grid.getTile(7, 11)->type = Tile::DoubleWord;
    grid.getTile(11, 11)->type = Tile::TripleLetter;
    grid.getTile(14, 11)->type = Tile::TripleWord;

    grid.getTile(1, 12)->type = Tile::DoubleLetter;
    grid.getTile(4, 12)->type = Tile::DoubleLetter;
    grid.getTile(10, 12)->type = Tile::DoubleLetter;
    grid.getTile(13, 12)->type = Tile::DoubleLetter;

    grid.getTile(2, 13)->type = Tile::DoubleLetter;
    grid.getTile(5, 13)->type = Tile::DoubleWord;
    grid.getTile(9, 13)->type = Tile::DoubleWord;
    grid.getTile(12, 13)->type = Tile::DoubleLetter;

    grid.getTile(3, 14)->type = Tile::TripleWord;
    grid.getTile(6, 14)->type = Tile::TripleLetter;
    grid.getTile(8, 14)->type = Tile::TripleLetter;
    grid.getTile(11, 14)->type = Tile::TripleWord;

    return grid;
}

Grid Grid::Small()
{
    Grid grid(11, 11);

    grid.getTile(0, 0)->type = Tile::TripleLetter;
    grid.getTile(2, 0)->type = Tile::TripleWord;
    grid.getTile(8, 0)->type = Tile::TripleWord;
    grid.getTile(10, 0)->type = Tile::TripleLetter;

    grid.getTile(1, 1)->type = Tile::DoubleWord;
    grid.getTile(5, 1)->type = Tile::DoubleWord;
    grid.getTile(9, 1)->type = Tile::DoubleWord;

    grid.getTile(0, 2)->type = Tile::TripleWord;
    grid.getTile(2, 2)->type = Tile::DoubleLetter;
    grid.getTile(4, 2)->type = Tile::DoubleLetter;
    grid.getTile(6, 2)->type = Tile::DoubleLetter;
    grid.getTile(8, 2)->type = Tile::DoubleLetter;
    grid.getTile(10, 2)->type = Tile::TripleWord;

    grid.getTile(3, 3)->type = Tile::TripleLetter;
    grid.getTile(7, 3)->type = Tile::TripleLetter;

    grid.getTile(2, 4)->type = Tile::DoubleLetter;
    grid.getTile(8, 4)->type = Tile::DoubleLetter;

    grid.getTile(1, 5)->type = Tile::DoubleWord;
    grid.getTile(5, 5)->type = Tile::Start;
    grid.getTile(9, 5)->type = Tile::DoubleWord;

    grid.getTile(2, 6)->type = Tile::DoubleLetter;
    grid.getTile(8, 6)->type = Tile::DoubleLetter;

    grid.getTile(3, 7)->type = Tile::TripleLetter;
    grid.getTile(7, 7)->type = Tile::TripleLetter;

    grid.getTile(0, 8)->type = Tile::TripleWord;
    grid.getTile(2, 8)->type = Tile::DoubleLetter;
    grid.getTile(4, 8)->type = Tile::DoubleLetter;
    grid.getTile(6, 8)->type = Tile::DoubleLetter;
    grid.getTile(8, 8)->type = Tile::DoubleLetter;
    grid.getTile(10, 8)->type = Tile::TripleWord;

    grid.getTile(1, 9)->type = Tile::DoubleWord;
    grid.getTile(5, 9)->type = Tile::DoubleWord;
    grid.getTile(9, 9)->type = Tile::DoubleWord;

    grid.getTile(0, 10)->type = Tile::TripleLetter;
    grid.getTile(2, 10)->type = Tile::TripleWord;
    grid.getTile(8, 10)->type = Tile::TripleWord;
    grid.getTile(10, 10)->type = Tile::TripleLetter;

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

Grid::Tile *Grid::getTile(size_t x, size_t y) const
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

    while(*i < i_max && word.length() != index)
    {
        Tile *tile = getTile(x, y);

        if(tile->value == ' ')
        {
            const char new_value = word[index++];
            tile->value = tolower(new_value);
            tile->wild = new_value < 'a';
            tile->cross_check = true;
        }

        i[0]++;
    }
}

void Grid::fetch(size_t x, size_t y, bool horizontal, std::string &word) const
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

bool Grid::check(size_t x, size_t y, bool horizontal) const
{
    bool connected = false;

    std::string word;
    fetch(x, y, horizontal, word);

    if(!validWords.contains(word))
    {
        return false;
    }

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

    for(size_t index = 0; index < word.length() && *i < i_max; index++)
    {
        const Tile *tile = getTile(x, y);

        if(tile->cross_check)
        {
            std::string word;
            fetch(x, y, !horizontal, word);
            if(word.length() > 1 && !validWords.contains(word))
            {
                return false;
            }
        }

        if(!tile->cross_check || tile->type == Tile::Type::Start)
        {
            connected = true;
        }

        i[0]++;
    }

    return connected;
}

void Grid::calculateAnchors(std::vector<Anchor> &anchors) const
{
    for(size_t x = 0; x < w; x++)
    {
        for(size_t y = 0; y < h; y++)
        {
            if(getTile(x, y)->value != ' ')
            {
                if(x == 0 || getTile(x - 1, y)->value == ' ')
                {
                    anchors.emplace_back(x, y, true);
                }
                if(y == 0 || getTile(x, y - 1)->value == ' ')
                {
                    anchors.emplace_back(x, y, false);
                }
            }
	    else
	    {
               if(x > 0 && getTile(x - 1, y)->value != ' ' ||
                  x < w - 1  && getTile(x + 1, y)->value != ' ')
	       {
                    anchors.emplace_back(x, y, false);
	       }
               if(y > 0 && getTile(x, y - 1)->value != ' ' ||
                  y < h - 1 && getTile(x, y + 1)->value != ' ')
	       {
                    anchors.emplace_back(x, y, true);
	       }
	    }
        }
    }

    if(anchors.empty())
    {
        anchors.emplace_back(w / 2, h / 2, true);
        anchors.emplace_back(w / 2, h / 2, false);
    }
}

std::set<Grid::Placement> Grid::calculatePlacements(std::string available) const
{
    std::set<Placement> placements;

    std::vector<Anchor> anchors;
    calculateAnchors(anchors);

    Permutation permutation(available);

    for(const std::string &letters : permutation.results)
    {
        for(const Anchor &anchor : anchors)
        {
            for(size_t i = 0; i <= letters.length(); i++)
            {
                size_t x;
                size_t y;

                if(anchor.horizontal)
                {
                    if(i > anchor.x)
                    {
                        break;
                    }

                    x = anchor.x - i;
                    y = anchor.y;
                }
                else
                {
                    if(i > anchor.y)
                    {
                        break;
                    }

                    x = anchor.x;
                    y = anchor.y - i;
                }

                Grid copy = *this;

                for(size_t x = 0; x < w; x++)
                {
                    for(size_t y = 0; y < h; y++)
                    {
                        copy.getTile(x, y)->cross_check = false;
                    }
                }

                copy.insert(x, y, anchor.horizontal, letters);

                if(copy.check(x, y, anchor.horizontal))
                {
                    std::string word;
                    copy.fetch(x, y, anchor.horizontal, word);

                    const int score = copy.score(x, y, anchor.horizontal);
/*
                    printf(
                        "Inserting [%zu,%zu,%c] %s (%d)\n",
                        x,
                        y,
                        anchor.horizontal ? 'H' : 'V',
                        word.data(),
                        score
                    );
*/
                    if(score)
                    {
                        placements.emplace(x, y, anchor.horizontal, word, letters, score);
                    }
                }
            }
        }
    }

    return placements;

}

void Grid::calculateBestMove(std::string available)
{
    std::vector<Anchor> anchors;
    calculateAnchors(anchors);
/*
    for(const Anchor &anchor : anchors)
    {
        printf(
            "[%zu,%zu,%c]\n",
            anchor.x,
            anchor.y,
            anchor.horizontal ? 'H' : 'V'
        );
    }
*/
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point t2;

    std::set<Placement> placements = calculatePlacements(available);
    t2 = std::chrono::steady_clock::now();

    std::chrono::duration<double> timeElapsedDuration =
        std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Time elapsed: " << timeElapsedDuration.count() << " seconds." << std::endl;
    message = "Done!";

    for(const Placement &placement : placements)
    {
        printf("[%zu,%zu,%c] %s (%d)\n", placement.x, placement.y, placement.horizontal ? 'H' : 'V',  placement.word.data(), placement.score);
    }

    if(!placements.empty())
    {
        const Placement &highest_score = *placements.rbegin();
        this->insert(highest_score.x, highest_score.y, highest_score.horizontal, highest_score.letters);
    }
}

bool Grid::validateWords(bool horizontal) const
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
                    if(!validWords.contains(word))
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

bool Grid::validateWords() const
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

bool Grid::validate() const
{
    bool result = validateLattice() && validateWords();

    if(result)
    {
        message = "Validation successful.";
    }

    return result;
}

int Grid::score(size_t x, size_t y, bool horizontal, bool recursive)
{
    int word_score = 0, adjacent_score = 0;

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

    int word_multiplier = 1;
    int tile_count = 0, new_tile_count = 0;
    bool cross_check = false;

    while(*i < i_max)
    {
        const Tile *tile = getTile(x, y);

        if(tile->value == ' ')
        {
            break;
        }

        int tile_multiplier = 1;

        if(tile->cross_check)
        {
            switch(tile->type)
            {
                case Tile::DoubleLetter:
                    tile_multiplier = 2; break;
                case Tile::TripleLetter:
                    tile_multiplier = 3; break;
                case Tile::DoubleWord:
                    word_multiplier *= 2; break;
                case Tile::TripleWord:
                    word_multiplier *= 3; break;
            }

            if(recursive)
            {
                adjacent_score += score(x, y, !horizontal, false);
            }

            cross_check = true;
	    new_tile_count++;
        }

        if(!tile->wild)
        {
            word_score += tile_multiplier * charScores[toupper(tile->value)];
        }

        tile_count++;
        i[0]++;
    }

    if(cross_check && tile_count > 1)
    {
        word_score *= word_multiplier;
	word_score += adjacent_score;

        if(new_tile_count >= 7)
        {
            word_score += 35;
        }

        return word_score;
    }

    return 0;
}
