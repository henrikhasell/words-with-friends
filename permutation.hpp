#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>

class Permutation
{
    static const char wildcard_values[26];
public:
    explicit Permutation(const std::string &input);
    std::set<std::string> results;
private:
    void iteration(std::string str, size_t j, size_t limit);
};

#endif
