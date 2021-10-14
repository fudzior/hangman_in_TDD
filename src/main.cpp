#include "word.hpp"
#include "game.hpp"
#include "generateTextFromFile.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>


int main()
{
    std::cout<<"From hangman main.cpp:"<<std::endl;

    //generateTextFromFile();

    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("Gosia");

    Game game(wordPtr);

    game.setInput(std::cin);

    game.playGame();

    return 0;
}