/*
 * TicTacToeGame.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: joeynorkin
 */
#include "TicTacToeGame.hpp"
#include <iostream>

TicTacToeGame::TicTacToeGame() {
    initializeBoard();
}

void TicTacToeGame::playGame() {
    clearBoard();

    displayLogo();

    char player1 = 'X';
    char player2 = 'O';

    char currentPlayer = player1;
    bool done = false;

    int x, y;

    int turn = 0;

    while (!done) {
        printBoard();

        std::cout << currentPlayerMessage(currentPlayer, player1, player2) << std::endl;

        x = getXCoord();
        y = getYCoord();
        if (placeMarker(x, y, currentPlayer) == false) {
            std::cout << "That spot is occupied!\n";
        } else {
            turn++;

            // there cannot be a victory with only 4 turns
            if (turn >= 5 && checkForVictory()) {
                printBoard();
                std::string winningPlayer = (currentPlayer == player1) ? "Player 1" : "Player 2";
                std::cout << "The game is over! " << winningPlayer << " has won!\n";
                done = true;
            } else if (turn == 9) {
                printBoard();
                std::cout << "It's a tie game!\n";
                done = true;
            }

            // switch players
            if (currentPlayer == player1) {
                currentPlayer = player2;
            } else {
                currentPlayer = player1;
            }
        }
    }
}

std::string TicTacToeGame::currentPlayerMessage(char currentPlayer, char player1, char player2) {
    return currentPlayer == player1 ? "Player 1's turn (X)." : "Player 2's turn (O).";
}

int TicTacToeGame::getXCoord() {
    bool badInput = true;
    int x = 0;

    while (badInput) {
        std::cout << "Enter the X coordinate: ";
        std::cin >> x;

        if (x < 1 || x > 3) {
            std::cout << "Invalid Coordinate!\n";
        } else {
            badInput = false;
        }
    }

    return x - 1;
}

int TicTacToeGame::getYCoord() {
    bool badInput = true;
    int y = 0;

    while (badInput) {
        std::cout << "Enter the Y coordinate: ";
        std::cin >> y;

        if (y < 1 || y > 3) {
            std::cout << "Invalid Coordinate!\n";
        } else {
            badInput = false;
        }
    }

    return y - 1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) {
    if (_board[y][x] != ' ') {
        return false;
    }

    _board[y][x] = currentPlayer;
    return true;
}

bool TicTacToeGame::checkForVictory() {

    // check the rows
    for (int y = 0; y < 3; y++) {
        if (_board[y][0] != ' ' && _board[y][0] == _board[y][1] && _board[y][1] == _board[y][2]) {
            return true;
        }
    }

    // check columns
    for (int x = 0; x < 3; x++) {
        if (_board[0][x] != ' ' && _board[0][x] == _board[1][x] && _board[1][x] == _board[2][x]) {
            return true;
        }
    }

    // check diagonals
    if (_board[0][0] != ' ' &&_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2]) {
        return true;
    }

    if (_board[0][2] != ' ' && _board[0][2] == _board[1][1] && _board[1][1] == _board[2][0]) {
        return true;
    }

    return false;
}

void TicTacToeGame::initializeBoard() {
    clearBoard();
}

void TicTacToeGame::clearBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _board[i][j] = ' ';
        }
    }
}

void TicTacToeGame::printBoard() {
    std::cout << std::endl;
    std::cout << "     1   2   3  " << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "   -------------" << std::endl;
        std::cout << " " << i + 1 << " " << "|";
        for (int j = 0; j < 3; j++) {
            std::cout << " " << _board[i][j] << " " << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "   -------------";
    std::cout << std::endl;
    std::cout << std::endl;
}

void TicTacToeGame::displayLogo() {
	std::string logo =
			"  //////// // ////////   //////// //////// ////////   //////// //////// ////////\n"
			"   ///    // ///          ///    ///   // ///          ///    ///   // ///      \n"
			"  ///    // ///          ///    //////// ///          ///    ///   // ////////  \n"
			" ///    // ///          ///    ///   // ///          ///    ///   // ///        \n"
			"///    // ////////     ///    ///   // ////////     ///    //////// ////////    ";

	std::cout << "\n\n\n" << logo << "\n\n\n";
}
