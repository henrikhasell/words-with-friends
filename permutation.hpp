#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>
#include "grid.hpp"

class Permutation
{
	static const char wildcard_values[26];
public:
	Permutation(
		std::string input,
		size_t x,
		size_t y,
		bool horizontal,
		const Grid &grid);

	std::set<std::string> results;
private:
	void iteration(std::string str, std::string res);
	size_t x;
	size_t y;
	bool horizontal;
	const Grid *grid;
};

#endif