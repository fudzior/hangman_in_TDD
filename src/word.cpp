#include "word.hpp"

#include <iostream>

std::string Word::getHiddenWord()
{
    return hiddenWord;
}

void Word::setFoundWord()
{
    for (auto it=hiddenWord.begin(); it<hiddenWord.end(); ++it)
    {
        foundWord.push_back('_');
    }
}

std::string Word::getFoundWord()
{
    return foundWord;
}