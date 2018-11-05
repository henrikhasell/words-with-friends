#ifndef PREMUTATION_HPP
#define PREMUTATION_HPP

#include <string>
#include <set>

class Permutation
{
    static const char wildcard_values[26];
public:
    Permutation(const std::string &input);
    std::set<std::string> results;
private:
    void iteration(const std::string &str, const std::string &res);
};

#endif
