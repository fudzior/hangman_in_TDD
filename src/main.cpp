#include "word.hpp"
#include "game.hpp"
#include "wordGenerator.hpp"
#include "generateTextFromFile.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>


int main()
{
    std::cout<<"From hangman main.cpp:"<<std::endl;
    
    std::string textGeneratedFromFile = generateTextFromFile("animals.txt");

    const unsigned MINNUMBERSOFLETTERS = 6;

    WordGenerator wordGenerator(textGeneratedFromFile);
    std::string generatedWord = wordGenerator.getLongWord(MINNUMBERSOFLETTERS);

    std::unique_ptr<Word> wordPtr = std::make_unique<Word>(generatedWord);

    Game game(std::move(wordPtr));
    game.setInput(std::cin);
    game.playGame();

    return 0;
}