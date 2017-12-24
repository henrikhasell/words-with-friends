#include "permutation.hpp"
#include <iostream>

const char Permutation::wildcard_values[26] = {
	'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l',
	'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x',
	'y', 'z'
};

Permutation::Permutation(std::string input)
{
	iteration(input, "");
}

void Permutation::iteration(std::string str, std::string res)
{
	results.push_back(res);

	for(size_t i = 0; i < str.length(); i++)
	{
		iteration(std::string(str).erase(i, 1), res + str[i]);
	}
}