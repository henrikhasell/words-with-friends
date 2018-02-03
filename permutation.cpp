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

Permutation::Permutation(std::string input)
{
	std::set<std::string> uniquePermutations;

	iteration(uniquePermutations, input, "");

	for(const char &letter : input)
	{
		if(letter == '*')
		{
			// TODO: Remove this.
			input.erase(std::remove(input.begin(), input.end(), '*'), input.end());

			for(const char &wildcard : wildcard_values)
			{
				iteration(uniquePermutations, input + wildcard, "");
			}
		}
	}

	// TODO: Resize vector before this.
	std::copy(
		uniquePermutations.begin(),
		uniquePermutations.end(),
		std::back_inserter(results));
}

void Permutation::iteration(std::set<std::string> &uniquePermutations, std::string str, std::string res)
{
	uniquePermutations.insert(res);

	for(size_t i = 0; i < str.length(); i++)
	{
		iteration(uniquePermutations, std::string(str).erase(i, 1), res + str[i]);
	}
}
