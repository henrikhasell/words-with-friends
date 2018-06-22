#include "trie.hpp"

bool Trie::contains(const std::string &string, bool *valid) const
{
	std::set<Segment>::iterator iterator = children.find(string[0]);

	if(iterator != children.end())
	{
		const Segment &segment = *iterator;

		if(string.length() == 1)
		{
			if(valid)
			{
				*valid = segment.valid;
			}
			return true;
		}

		return segment.contains(string.substr(1));
	}
	
	return false;
}

void Trie::insert(const std::string &string)
{
	std::set<Segment>::iterator iterator = children.find(string[0]);

	if(iterator == children.end())
	{
		children.insert(string);
	}
	else
	{
		((Segment)*iterator).insert(string.substr(1));
	}
}

Segment::Segment(char character) :
	character(character)
{
	
}

Segment::Segment(const std::string &string) :
	valid(string.length() == 1)
{
	if(!valid)
	{
		insert(string.substr(1));
	}
	
	character = string[0];
}

bool Segment::operator< (const Segment &right) const
{
	return character < right.character;
}	