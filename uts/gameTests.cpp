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

    std::istringstream iss;

    void updateIss(std::string newValue)
    {
    iss.str("");
    iss.clear();
    iss.str(newValue);
    }
};


class gameWithA: public ::testing::Test
{
public:
    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("a");
};


TEST_F(gameWithGosia, whenUserInputIsGOSIAThenGameStateIsWon)
{
    updateIss("GOSIA");
    Game game(wordPtr); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsMalGosiaThenGameStateIsWon_UsingPlayGame)
{
    updateIss("MalGosia");
    Game game(wordPtr); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsRychuThenGameStateIsLoose_UsingPlayGame)
{
    updateIss("Rychu");
    Game game(wordPtr); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, loose);
}

TEST_F(gameWithA, whenUserGaveAthenHeWons)
{
    std::istringstream iss("a");
    Game game(wordPtr); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsRychuThenGameStateIsLoose)
{
    Game game(wordPtr);
    updateIss("R");
    game.setInput(iss);
    game.playRound();
    updateIss("y");
    game.setInput(iss);
    game.playRound();
    updateIss("c");
    game.setInput(iss);
    game.playRound();
    updateIss("h");
    game.setInput(iss);
    game.playRound();
    updateIss("u");
    game.setInput(iss);
    game.playRound();
    State result = game.getState();
    EXPECT_EQ(result, loose);
    std::string userInput = wordPtr->getFoundWord();
    EXPECT_EQ(userInput, "_____");
}

TEST_F(gameWithGosia, checkingIfUpdateIssMethodWork)
{
    Game game(wordPtr);
    updateIss("G");
    game.setInput(iss);
    game.playRound();
    updateIss("o");
    game.setInput(iss);
    game.playRound();
    updateIss("s");
    game.setInput(iss);
    game.playRound();
    updateIss("i");
    game.setInput(iss);
    game.playRound();
    updateIss("a");
    game.setInput(iss);
    game.playRound();

    std::string result = wordPtr->getFoundWord();
    EXPECT_EQ(result, "GOSIA");
}

TEST(checkInput, checkingIfMultipleFakeInputsWork)
{
    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("Gosia");
    Game game(wordPtr);
    std::istringstream iss("G");
    game.setInput(iss);
    game.playRound();
    iss.str("");
    iss.clear();
    iss.str("o");
    game.setInput(iss);
    game.playRound();
    iss.str("");
    iss.clear();
    iss.str("s");
    game.setInput(iss);
    game.playRound();
    iss.str("");
    iss.clear();
    iss.str("i");
    game.setInput(iss);
    game.playRound();
    iss.str("");
    iss.clear();
    iss.str("a");
    game.setInput(iss);
    game.playRound();

    std::string result = wordPtr->getFoundWord();
    EXPECT_EQ(result, "GOSIA");
}

TEST(checkInput, checkingIfFakeInputWork)
{
    std::istringstream iss("GOSIA");
    std::shared_ptr<Word> wordPtr = std::make_shared<Word>("Gosia");
    Game game(wordPtr);
    game.setInput(iss);
    std::string result = game.getInput();
    EXPECT_EQ(result, "GOSIA");
}

TEST_F(gameWithA, whenUserGaveBAndHiddenWordIsANumberOfLifesDecreasesFrom5To4)
{
    std::istringstream iss("b");
    Game game(wordPtr);
    game.setInput(iss);
    game.playRound();
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
    EXPECT_EQ(result, "A");
}