#pragma once

#include <string>

class Word
{
public:
    std::string getHiddenWord();
    void setFoundWord();
    std::string getFoundWord();
    bool findLetter(char input);
    
    Word(std::string input)
    {
        setHiddenWord(input);
        setFoundWord();
    };

private:
    std::string hiddenWord;
    std::string foundWord;
    void setHiddenWord(std::string input);
};