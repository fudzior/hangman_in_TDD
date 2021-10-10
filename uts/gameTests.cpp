#include "game.hpp"
#include "word.hpp"
#include "gtest/gtest.h"

#include <memory>
#include <sstream>
//#include <iostream>

class gameWithGosia: public ::testing::Test
{
public:
    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("Gosia");

};


class gameWithA: public ::testing::Test
{
public:
    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("a");
};


/*TEST_F(gameWithGosia, whenUserGaveRychuthenGameStatusIsLoose)
{
    Game game(wordPtr);
    std::istringstream iss("R y c h u");
    char value = readIntFromStream(iss)
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, loose);
}*/

TEST_F(gameWithGosia, checkingIfFakeInputIsWorking)
{
    std::istringstream iss("Gosia");
    Game game(wordPtr);
    std::string result = game.getInput(iss);
    EXPECT_EQ(result, "Gosia");
}

TEST_F(gameWithGosia, whenUserGaveGosiathenGameStatusIsWon)
{
    Game game(wordPtr);
    game.playRound('G');
    game.playRound('o');
    game.playRound('s');
    game.playRound('i');
    game.playRound('a');
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithA, whenUserGaveBAndHiddenWordIsANumberOfLifesDecreasesFrom5To4)
{
    Game game(wordPtr);
    game.playRound('b');
    unsigned result = game.getNumberOfLifes();
    EXPECT_EQ(result, 4);
}

TEST_F(gameWithA, whenHiddenWordIsAAndFoundWordIsAGameStateIsWon)
{
    Game game(wordPtr);
    wordPtr->findLetter('a');
    State result = game.setState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithA, whenGameIsCreateDStateIsOn)
{
    Game game(wordPtr);
    State result = game.setState();
    EXPECT_EQ(result, on);
}

TEST_F(gameWithA, whenNumberOfLifesIs0ThenGameIsLoose)
{
    Game game(wordPtr);
    game.setNumberOfLifes(0);
    State result = game.setState();
    EXPECT_EQ(result, loose);
}

TEST_F(gameWithA, whenGameIsStartedthenNumberOfLifeIs5)
{
    Game game(wordPtr);
    unsigned result = game.getNumberOfLifes();
    EXPECT_EQ(result, 5);
}

TEST_F(gameWithA, checkIfPreparedPtrForWordIsWorking)
{
    wordPtr->findLetter('a');
    std::string result = wordPtr->getFoundWord();
    EXPECT_EQ(result, "a");
}