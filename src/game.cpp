#include "game.hpp"
#include "word.hpp"

#include <memory>
#include <iostream>
#include <string>

unsigned Game::getNumberOfLifes()
{
    return numberOfLifes;
}

void Game::setNumberOfLifes(unsigned input)
{
    numberOfLifes=input;
}

State Game::setState()
{
    if (numberOfLifes==0)
        return gameState = loose;

    std::string word = wordPtr->getFoundWord();

    for (auto ch :word)
    {
        if (ch =='_')
            return gameState = on;
    }

    return gameState =won;
}

State Game::getState()
{
    return gameState;
}

void Game::playRound(char input)
{
    bool letterFound = wordPtr->findLetter(input);

    if (!letterFound)
        --numberOfLifes;

    setState();
}

std::string Game::getInput (std::istream& input)
{
    std::string result ="";
    input >> result;
    return result;
}