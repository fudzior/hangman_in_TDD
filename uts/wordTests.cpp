#include "word.hpp"
#include "gtest/gtest.h"


TEST(wordTest, whenUserGaveBAndHiddenWordIsKasiaThenFoundWordIs_____AndFindLetterReturnsTrue)
{
    Word word("kasia");
    bool result = word.findLetter('b');
    std::string foundWord_ = word.getFoundWord();
    EXPECT_EQ(foundWord_, "_____");
    EXPECT_EQ(result, false);
}

TEST(wordTest, whenUserGaveAAndHiddenWordIsKasiaThenFoundWordIs_a__aAndFindLetterReturnsFalse)
{
    Word word("kasia");
    bool result = word.findLetter('a');
    std::string foundWord_ = word.getFoundWord();
    EXPECT_EQ(foundWord_, "_a__a");
    EXPECT_EQ(result, true);
}

TEST(wordTest, whenWordIsCreatedAndHiddenWordIsKasiaThenFoundWordIs_____)
{
    Word word("kasia");
    std::string result = word.getFoundWord();
    EXPECT_EQ(result, "_____");
}

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