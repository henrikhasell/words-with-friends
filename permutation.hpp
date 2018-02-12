#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>

class Permutation
{
	static const char wildcard_values[26];
public:
	Permutation(std::string input);
	std::set<std::string> results;
private:
	void iteration(std::string str, std::string res);
	bool wild;
};

#endif