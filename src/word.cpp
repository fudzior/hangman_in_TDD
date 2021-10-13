#include "word.hpp"

#include <iostream>
#include <cctype>

void Word::setHiddenWord(const std::string& input)
{
    std::string result="";
    char tempLetter;

    for (auto letter : input)
    {
        tempLetter=std::toupper(letter);
        result.push_back(tempLetter);
    }
    hiddenWord = result;
}

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

bool Word::findLetter(char input)
{
    bool letterFound =false;
    char upperLetter = std::toupper(input);

    for (size_t i=0; i<hiddenWord.size(); ++i)
    {
        if (hiddenWord[i]==upperLetter)
        {
            foundWord[i]=upperLetter;
            letterFound=true;
        }
    }
return letterFound;
}