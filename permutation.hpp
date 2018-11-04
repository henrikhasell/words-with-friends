#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>
#include "grid.hpp"

class Permutation
{
    struct Tile
    {
        char value;
        bool wild;
    };
    static const char wildcard_values[26];
public:
    Permutation(const std::string &input);
    std::set<std::string> results;
private:
    void iteration(const std::string &str, const std::string &res);
};

#endif
