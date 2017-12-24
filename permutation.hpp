#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <vector>

struct Permutation
{
	Permutation(std::string input);
	std::vector<std::string> results;
private:
	void iteration(std::string str, std::string res);
	static const char wildcard_values[26];
};

#endif