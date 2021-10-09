#pragma once

#include <string>

class Word
{
public:
    std::string getHiddenWord();
    void setFoundWord();
    std::string getFoundWord();
    
    Word(std::string input):hiddenWord(input)
    {
        setFoundWord();
    };

private:
    std::string hiddenWord;
    std::string foundWord;

};