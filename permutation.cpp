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
    iteration(input, 0, input.length() - 1);
    results.begin();
}

void Permutation::iteration(std::string str, size_t j, size_t limit)
{
	if(j == limit)
	{
		results.insert(str);
	}
	else
	{
		for(size_t i = j; i <= limit; i++)
		{
			const char c = str[j];

			str[j] = str[i];
			str[i] = c;

			iteration(str, j + 1, limit);
		}
	}
}
