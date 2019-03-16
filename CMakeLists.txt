cmake_minimum_required(VERSION 3.13.4)
project(TicTacToe VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++11 support has been enabled by default.")

add_subdirectory(src)

add_executable(tictactoe main.cpp)
target_link_libraries(tictactoe PRIVATE tictactoegame)
