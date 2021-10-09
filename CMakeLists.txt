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

add_library(implementations src/word.cpp)
target_include_directories(implementations PUBLIC include)

add_executable(game src/main.cpp)
target_link_libraries(game implementations)

add_executable(tests uts/wordTests.cpp)
target_link_libraries(tests gtest_main implementations)


add_custom_target(run
                  COMMAND "./game")

add_custom_target(test
                  COMMAND "./tests"
                  DEPENDS tests)
                
                  