#include "game.hpp"

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
        gameState = loose;

    return gameState;
}