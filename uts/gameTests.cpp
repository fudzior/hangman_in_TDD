#include "game.hpp"
#include "word.hpp"
#include "gtest/gtest.h"

#include <memory>
#include <sstream>


class gameWithGosia: public ::testing::Test
{
public:
    std::unique_ptr<Word> wordPtr = std::make_unique<Word>("Gosia");

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
    std::unique_ptr<Word> wordPtr = std::make_unique<Word>("a");
};


TEST_F(gameWithGosia, whenUserInputIsGOSIAThenGameStateIsWon)
{
    updateIss("GOSIA");
    Game game(std::move(wordPtr)); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsMalGosiaThenGameStateIsWon_UsingPlayGame)
{
    updateIss("MalGosia");
    Game game(std::move(wordPtr)); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsRychuThenGameStateIsLoose_UsingPlayGame)
{
    updateIss("Rychu");
    Game game(std::move(wordPtr)); 
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, loose);
}

TEST_F(gameWithA, whenUserGaveAthenHeWons)
{
    std::istringstream iss("a");
    Game game(std::move(wordPtr));
    game.setInput(iss);
    game.playGame();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithGosia, whenUserInputIsRychuThenGameStateIsLoose)
{
    Game game(std::move(wordPtr));
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
}

TEST_F(gameWithGosia, checkingIfUpdateIssMethodWork)
{
    Game game(std::move(wordPtr));
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

    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST(checkInput, checkingIfMultipleFakeInputsWork)
{
    std::unique_ptr<Word> wordPtr = std::make_unique<Word>("Gosia");
    Game game(std::move(wordPtr));
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

    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST(checkInput, checkingIfFakeInputWork)
{
    std::istringstream iss("GOSIA");
    std::unique_ptr<Word> wordPtr = std::make_unique<Word>("Gosia");
    Game game(std::move(wordPtr));
    game.setInput(iss);
    std::string result = game.getInput();
    EXPECT_EQ(result, "GOSIA");
}

TEST_F(gameWithA, whenUserGaveBAndHiddenWordIsANumberOfLifesDecreasesFrom5To4)
{
    std::istringstream iss("b");
    Game game(std::move(wordPtr));
    game.setInput(iss);
    game.playRound();
    unsigned result = game.getNumberOfLifes();
    EXPECT_EQ(result, 4);
}

TEST_F(gameWithA, whenHiddenWordIsAAndIUserGaveAGameStateIsWon)
{
    std::istringstream iss("a");
    Game game(std::move(wordPtr));
    game.setInput(iss);
    game.playRound();
    State result = game.getState();
    EXPECT_EQ(result, won);
}

TEST_F(gameWithA, whenGameIsCreatedStateIsOn)
{
    Game game(std::move(wordPtr));
    State result = game.getState();
    EXPECT_EQ(result, on);
}

/*//since setState() and setNumberofLifes is private, this test is obsolete because it will behave like whenUserInputIsRychuThenGameStateIsLoose 
TEST_F(gameWithA, whenNumberOfLifesIs0ThenGameIsLoose) 
{
    std::istringstream iss("b");
    Game game(std::move(wordPtr));
    game.setInput(iss);
    game.playRound(); //need to play 5 rounds like in whenUserInputIsRychuThenGameStateIsLoose
    unsigned result1 = game.getNumberOfLifes();
    State result2 = game.getState();
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, loose);
}*/

TEST_F(gameWithA, whenGameIsStartedthenNumberOfLifeIs5)
{
    Game game(std::move(wordPtr));
    unsigned result = game.getNumberOfLifes();
    EXPECT_EQ(result, 5);
}

TEST_F(gameWithA, checkIfPreparedPtrForWordIsWorking)
{
    wordPtr->findLetter('a');
    std::string result = wordPtr->getFoundWord();
    EXPECT_EQ(result, "A");
}