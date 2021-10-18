#pragma once

#include "word.hpp"
#include <memory>
#include <iostream>

enum State {on, loose, won};

class Game
{
public:
    unsigned getNumberOfLifes();

    State getState();

    void setInput (std::istream& input);
    std::string getInput();

    void playRound(); 
    void playGame();

    Game(std::unique_ptr<Word> wordPtr_):numberOfLifes(5),
                                        gameState(on),
                                        wordPtr(std::move(wordPtr_)),
                                        inputIndex(0)
                                        {
                                            std::cout<<"Found word: "<< wordPtr->getFoundWord() <<std::endl;
                                            std::cout<<"Number of lifes:"<< numberOfLifes << std::endl;
                                        };
   
private:
    unsigned numberOfLifes;
    State gameState;
    std::unique_ptr<Word> wordPtr;
    std::string userInput;
    size_t inputIndex;

    void setNumberOfLifes(unsigned input);
    State setState();

};