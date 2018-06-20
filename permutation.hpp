#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>

class Permutation
{
	static const char wildcard_values[26];
public:
	Permutation( input,
	size_t x,
	size_t y,
	size_t offset,
	bool horizon
	std::stringtal);
	std::set<std::string> results;
private:
	void iteration(std::string str, std::string res);
	bool wild;
	size_t x;
	size_t y;
	size_t offset;
	bool horizontal;
};

#endif