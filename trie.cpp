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

		return segment.contains(string.substr(1), valid);
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
	    Segment &segment = (Segment&)*iterator;

	    if(string.length() == 1)
        {
            segment.valid = true;
        }
        else
        {
            segment.insert(string.substr(1));
        }
	}
}

void Trie::display(size_t indentation) const
{
	for(const Segment &segment : children)
	{
		segment.display(indentation);
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

void Segment::display(size_t indentation) const
{
	for(size_t i = 0; i < indentation; i++)
	{
		std::cout << '\t';
	}
	
	std::cout << character << " (" << valid << ")" << std::endl;
		
	for(const Segment &segment : children)
	{
		segment.display(indentation + 1);
	}
}

bool Segment::operator< (const Segment &right) const
{
	return character < right.character;
}

bool Segment::operator> (const Segment &right) const
{
	return character > right.character;
}

bool Segment::operator<= (const Segment &right) const
{
	return character <= right.character;
}

bool Segment::operator>= (const Segment &right) const
{
	return character <= right.character;
}

bool Segment::operator== (const Segment &right) const
{
	return character == right.character;
}

bool Segment::operator!= (const Segment &right) const
{
	return character != right.character;
}