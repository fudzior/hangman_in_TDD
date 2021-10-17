cmake_minimum_required(VERSION 3.10)
project(hangman CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_MakeAvailable(googletest)

SET(SRCS
  src/word.cpp 
  src/game.cpp 
  src/wordGenerator.cpp 
  src/generateTextFromFile.cpp
)

add_library(implementations ${SRCS})
target_include_directories(implementations PUBLIC include)

add_executable(game src/main.cpp)
target_link_libraries(game implementations)

SET(UTS
  uts/wordTests.cpp 
  uts/gameTests.cpp 
  uts/wordGeneratorTests.cpp 
  uts/generateTextFromFileTests.cpp
)

add_executable(tests ${UTS})
target_link_libraries(tests gtest_main implementations)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textFiles/textForTests.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/textForTests.txt
${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textFiles/animals.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/animals.txt
${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_custom_target(run
                  COMMAND "./game")

add_custom_target(test
                  COMMAND "./tests"
                  DEPENDS tests)
                
                  