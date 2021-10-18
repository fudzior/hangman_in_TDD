#pragma once

#include <string>

class Word
{
public:
    std::string getHiddenWord();
    std::string getFoundWord();
    bool findLetter(char input);
    
    Word(const std::string& input)
    {
        setHiddenWord(input);
        setFoundWord();
    };

private:
    std::string hiddenWord;
    std::string foundWord;
    
    void setHiddenWord(const std::string& input);
    void setFoundWord();
};