#include "wordGenerator.hpp"
#include "gtest/gtest.h"


TEST(wordGeneratorTest, whenInputTextIsKasia__123_GosiaThenGetLongWordWith6ReturnsEmptyString)
{
    WordGenerator wordGenerator("!Kasia  123 Gosia?");
    std::string result1 = wordGenerator.getLongWord(6);
    EXPECT_EQ(result1, "");
}

TEST(wordGeneratorTest, whenInputTextIsKasia__123_MalgosiaThenGetLongWordWith6ReturnsMalgosia)
{
    WordGenerator wordGenerator("!Kasia  123 Malgosia?");
    std::string result1 = wordGenerator.getLongWord(6);
    EXPECT_EQ(result1, "Malgosia");
}

TEST(wordGeneratorTest, whenInputTextIsKasia__123_GosiaThenFirstGetWordIsKasiaSecondGetWordIsGosia)
{
    WordGenerator wordGenerator("!Kasia  123 Gosia?");
    std::string result1 = wordGenerator.getWord();
    std::string result2 = wordGenerator.getWord();
    EXPECT_EQ(result1, "Kasia");
    EXPECT_EQ(result2, "Gosia");
}

TEST(wordGeneratorTest, whenInputTextIs123_GosiaThenGetWordReturnsGosia)
{
    WordGenerator wordGenerator("123 Gosia");
    std::string result = wordGenerator.getWord();
    EXPECT_EQ(result, "Gosia");
}

TEST(wordGeneratorTest, whenInputTextIs123_GosiaGetInputTextReturn____Gosia)
{
    WordGenerator wordGenerator("123 Gosia");
    std::string result = wordGenerator.getInputText();
    EXPECT_EQ(result, "    Gosia");
}

TEST(wordGeneratorTest, whenInputTextIs_Hello__Gosia_And___KasiaFourthWordIsKasia)
{
    WordGenerator wordGenerator("Hello  Gosia and   Kasia");
    wordGenerator.getWord();
    wordGenerator.getWord();
    wordGenerator.getWord();
    std::string result = wordGenerator.getWord();
    EXPECT_EQ(result, "Kasia");
}

TEST(wordGeneratorTest, whenInputTextIs_Hello__GosiaNextWordIndexIs7)
{
    WordGenerator wordGenerator("Hello  Gosia");
    wordGenerator.getWord();
    unsigned result = wordGenerator.getnextWordIndex();
    EXPECT_EQ(result, 7);
}

TEST(wordGeneratorTest, whenInputTextIsHello_GosiaReturnHello)
{
    WordGenerator wordGenerator("Hello Gosia");
    std::string result = wordGenerator.getWord();
    EXPECT_EQ(result, "Hello");
}