#pragma once
#include <string>

class WordGenerator
{
public:
    std::string getWord();
    unsigned getnextWordIndex();
    std::string getInputText();

    WordGenerator(const std::string& input):nextWordIndex(0)
                                            {
                                                prepareInputText(input);
                                            };

private:
    std::string inputText;
    unsigned nextWordIndex;
    
    void prepareInputText (const std::string& input);
};