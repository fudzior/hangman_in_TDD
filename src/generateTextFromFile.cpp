#include "generateTextFromFile.hpp"
#include <iostream>
#include <fstream>

std::string generateTextFromFile(std::string fileName)
{
    std::string some_text;
    unsigned char c;
    std::ifstream inFile;

    inFile.open(fileName);
    if (!inFile)
        {
        std::cout << "Unable to open file";
        exit(1); 
        }

    while (inFile >> std::noskipws >> c)
        {
        some_text.push_back(c);
        }

    inFile.close();
    
    return some_text;
}