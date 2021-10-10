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

unsigned Word::findLetter(char input)
{
    bool letterFound =false;
    for (size_t i=0; i<hiddenWord.size(); ++i)
    {
        if (hiddenWord[i]==input)
        {
            foundWord[i]=input;
            letterFound=true;
        }
    }

    if (letterFound)
        return 0;
    else
        return 1;
}