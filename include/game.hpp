#pragma once

#include "word.hpp"
#include <memory>
#include <iostream>

enum State {on, loose, won};

class Game
{
public:
    unsigned getNumberOfLifes();
    void setNumberOfLifes(unsigned input);

    State setState();
    State getState();

    void setInput (std::istream& input);
    std::string getInput();

    void playRound();
    void playGame();
    
    Game(std::shared_ptr<Word> wordPtr_):numberOfLifes(5),
                                        gameState(on),
                                        wordPtr(wordPtr_),
                                        inputIndex(0){};

private:
    unsigned numberOfLifes;
    State gameState;
    std::shared_ptr<Word> wordPtr;
    std::string userInput;
    size_t inputIndex;
};