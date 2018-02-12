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
	iteration(input, "");

	if(wild)
	{
		for(const char &wildcard : wildcard_values)
		{
			iteration(input + wildcard, "");
		}
	}

}

void Permutation::iteration(std::string str, std::string res)
{
	results.insert(res);

	for(size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == '*')
		{
			wild = true;
		}
		else
		{
			iteration(std::string(str).erase(i, 1), res + str[i]);
		}
	}
}