#pragma once
#include <string>

class WordGenerator
{
public:
    std::string getWord();
    unsigned getnextWordIndex();

    WordGenerator(const std::string& input):inputText(input),
                                            nextWordIndex(0){};

private:
    std::string inputText;
    unsigned nextWordIndex;
};