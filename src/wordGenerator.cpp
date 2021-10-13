#include "wordGenerator.hpp"

std::string WordGenerator::getWord()
{
    std::string word = "";
    bool spaceOccured = false;

    for (auto it=inputText.begin()+nextWordIndex; it!=inputText.end(); ++it) 
    {
        if ((*it)!=' ' && !spaceOccured)
        {
            word.push_back(*it);
            ++nextWordIndex;
        }
        else if ((*it)==' ')
        {
            spaceOccured = true;
            ++nextWordIndex;
        }
        else if ((*it)!=' ' && spaceOccured)
            return word;
    }

    return word;
}

unsigned WordGenerator::getnextWordIndex()
{
    return nextWordIndex;
}
