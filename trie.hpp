#ifndef TRIE_HPP
#define TRIE_HPP

#include <set>
#include <string>

#include <iostream>

class Trie;
class Segment;

class Trie
{
public:
	bool contains(const std::string &string, bool *valid = nullptr) const;
	void insert(const std::string &string);
protected:
	std::set<Segment> children;
};

class Segment : public Trie
{
	friend class Trie;
public:
	Segment(const std::string &string);
	bool operator< (const Segment &right) const;
protected:
	Segment(char character);
	char character;
	bool valid;
};

#endif