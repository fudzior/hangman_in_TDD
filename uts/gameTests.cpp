#include "game.hpp"
#include "gtest/gtest.h"


TEST(gameTest, whenHiddenWordIsAAndFoundWordIsAThenGameStateIsWon)
{
    Game game;
    State result = game.setState();
    EXPECT_EQ(result, on);
}

TEST(gameTest, whenGameIsCreateDStateIsOn)
{
    Game game;
    State result = game.setState();
    EXPECT_EQ(result, on);
}

TEST(gameTest, whenNumberOfLifesIs0ThenGameIsLoose)
{
    Game game;
    game.setNumberOfLifes(0);
    State result = game.setState();
    EXPECT_EQ(result, loose);
}

TEST(gameTest, whenGameIsStartedthenNumberOfLifeIs5)
{
    Game game;
    unsigned result = game.getNumberOfLifes();
    EXPECT_EQ(result, 5);
}