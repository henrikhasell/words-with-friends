#include "permutation.hpp"
#include <algorithm>
#include <iostream>

const char Permutation::wildcard_values[26] = {
    'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

Permutation::Permutation(
    std::string input,
    size_t x,
    size_t y,
    bool horizontal,
    const Grid &grid
) :
    x(x),
    y(y),
    horizontal(horizontal),
    grid(&grid)
{
    for(size_t i = 0; i < input.length(); i++)
    {
        iteration(input, "");
    }
}

void Permutation::iteration(std::string str, std::string res)
{
    Grid copy = *grid;
    copy.insert(x, y, horizontal, res);

    results.insert(res);

    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] == '*')
        {
            for(char value : wildcard_values)
            {
                iteration(str.erase(i, 1), res + value);
            }
        }
        else
        {
            iteration(str.erase(i, 1), res + str[i]);
        }
    }
}
