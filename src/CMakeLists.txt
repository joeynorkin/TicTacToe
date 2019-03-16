add_library(tictactoegame STATIC TicTacToeGame.hpp TicTacToeGame.cpp)

target_include_directories(tictactoegame PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
