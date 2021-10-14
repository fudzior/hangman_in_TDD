#include "generateTextFromFile.hpp"
#include "gtest/gtest.h"

TEST(generatorTextFromFileTest, printSampleTextFromFileTxt)
{
    std::string fileName = "textForTests.txt";
    std::string result = generateTextFromFile(fileName);

    EXPECT_EQ(result, "Sample text from file.");
}