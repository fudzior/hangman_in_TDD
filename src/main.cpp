#include <iostream>
#include "word.hpp"

int main()
{
    std::cout<<"From hangman main"<<std::endl;

    Word word("gosia");
    std::cout<< word.getFoundWord() <<std::endl;

    return 0;
}