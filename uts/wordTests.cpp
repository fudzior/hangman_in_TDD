#include "word.hpp"
#include "gtest/gtest.h"

TEST(wordTest, whenGosiaIsSetHiddenWordWordThenReturnGosiaInGetHiddenWord)
{
    Word word("gosia");
    std::string result = word.getHiddenWord();
    EXPECT_EQ(result, "gosia");
}

TEST(wordTest, whenNothingIsSetHiddenWordWordThenReturnEmptyStringInGetHiddenWord)
{
    Word word("");
    std::string result = word.getHiddenWord();
    EXPECT_EQ(result, "");
}

TEST(wordTest, whenWordIsCreatedAndHiddenWordIsKasiaThenFoundWordIs_____)
{
    Word word("kasia");
    std::string result = word.getFoundWord();
    EXPECT_EQ(result, "_____");
}