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

void Game::setInput (std::istream& input)
{
    //CLASS WORD MANAGES UPPER AND LOWER CASE

    input >> userInput;

    inputIndex = 0;
}

std::string Game::getInput()
{
    return userInput;
}

void Game::playRound()
{
    char letter;
    
    if (inputIndex<userInput.size())
    {
        letter = userInput[inputIndex];

        if (letter==27)
        {
            gameState=loose;
            return;
        }
        ++inputIndex;
    }
    else
    {
        setInput(std::cin);
    }
    
    bool letterFound = wordPtr->findLetter(letter);

    if (!letterFound)
        --numberOfLifes;

    std::cout<<"Found word: "<< wordPtr->getFoundWord() <<std::endl;
    std::cout<<"Number of lifes:"<< numberOfLifes << std::endl;
    
    setState();
}

void Game::playGame()
{
    while (gameState==on)
    {
        playRound();
    }

    if (gameState==won)
        std::cout<<"You won!"<<std::endl;
    else if (gameState==loose)
    {
        std::cout<<"You loose"<<std::endl;
        std::cout<<"Hidden word was: "<<wordPtr->getHiddenWord()<<std::endl;
    }
}