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

Permutation::Permutation(const std::string &input)
{
    iteration(input, "");
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
