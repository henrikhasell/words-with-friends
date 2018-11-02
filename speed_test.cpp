#include "grid.hpp"
#include "trie.hpp"
#include <fstream>

#define PASS_1 25
#define PASS_2 10

std::string message;
std::map<char, int> charScores;
Trie validWords;

int main()
{
    charScores['A'] = 1;
    charScores['B'] = 4;
    charScores['C'] = 4;
    charScores['D'] = 2;
    charScores['E'] = 1;
    charScores['F'] = 4;
    charScores['G'] = 3;
    charScores['H'] = 3;
    charScores['I'] = 1;
    charScores['J'] = 10;
    charScores['K'] = 5;
    charScores['L'] = 2;
    charScores['M'] = 4;
    charScores['N'] = 2;
    charScores['O'] = 1;
    charScores['P'] = 4;
    charScores['Q'] = 10;
    charScores['R'] = 1;
    charScores['S'] = 1;
    charScores['T'] = 1;
    charScores['U'] = 2;
    charScores['V'] = 5;
    charScores['W'] = 4;
    charScores['X'] = 8;
    charScores['Y'] = 3;
    charScores['Z'] = 10;

    std::ifstream file;
    file.open("dictionary.txt");

    std::string word;
    while(file >> word)
    {
        for(char &i : word) i = tolower(i);
        validWords.insert(word);
    }

    Grid grid = Grid::Large();

    for(size_t i = 0; i < PASS_1; i++)
    {

        std::cout << "Pass " << (i+1) << std::endl;

        for(size_t i = 0; i < PASS_2; i++)
        {
            Grid copy = grid;

            copy.calculateBestMove("avocado");

            if(i == PASS_2 - 1)
            {
                grid = copy;
            }
        }
    }
}
