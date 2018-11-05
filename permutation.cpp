#include "permutation.hpp"
#include <algorithm>
#include <iostream>

const char Permutation::wildcard_values[26] = {
    'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z'
};

Permutation::Permutation(const std::string &input)
{
    iteration(input, "");
    results.begin();
}

void Permutation::iteration(const std::string &str, const std::string &res)
{
    results.insert(res);

    for(size_t i = 0; i < str.length(); i++)
    {
        const std::string str2 = std::string(str).erase(i, 1);

        if(str[i] == '*')
        {
            for(char value : wildcard_values)
            {
                iteration(str2, res + value);
            }
        }
        else
        {
            iteration(str2, res + str[i]);
        }
    }
}
