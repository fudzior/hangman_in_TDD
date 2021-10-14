#include "wordGenerator.hpp"

#include <iostream>

std::string WordGenerator::getWord()
{
    std::string word = "";
    bool spaceOccured = false;
    bool wordGenerated = false;

    for (auto it=inputText.begin()+nextWordIndex; it!=inputText.end(); ++it) 
    {
        if ((*it)!=' ' && spaceOccured && wordGenerated)
        {
            return word;
        }   
        else if ((*it)!=' ')
        {
            word.push_back(*it);
            wordGenerated = true;
            spaceOccured = false;
            ++nextWordIndex;
        }
        else if ((*it)==' ')
        {
            spaceOccured = true;
            ++nextWordIndex;
        }
    }

    return word;
}

unsigned WordGenerator::getnextWordIndex()
{
    return nextWordIndex;
}

void WordGenerator::prepareInputText (const std::string& input)
{
    inputText = "";

    for (auto symbol : input)
    {
        if (std::isalpha(symbol))
            inputText.push_back(symbol);
        else
            inputText.push_back(' ');
    }
}

std::string WordGenerator::getInputText()
{
    return inputText;
}