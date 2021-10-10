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
    void playRound(char input);
    std::string getInput (std::istream& input);
    
    Game(std::shared_ptr<Word> inputPtr):numberOfLifes(5),
                                        gameState(on),
                                        wordPtr(inputPtr){};

private:
    unsigned numberOfLifes;
    State gameState;
    std::shared_ptr<Word> wordPtr;
};