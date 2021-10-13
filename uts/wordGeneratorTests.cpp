#include "wordGenerator.hpp"
#include "gtest/gtest.h"


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