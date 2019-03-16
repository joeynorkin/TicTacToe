#ifndef TICTACTOEGAME_HPP_
#define TICTACTOEGAME_HPP_

#include <string>

class TicTacToeGame {
public:
    TicTacToeGame();
    void playGame();

private:
    int getXCoord();
    int getYCoord();
    bool placeMarker(int x, int y, char currentPlayer);

    bool checkForVictory();

    std::string currentPlayerMessage(char currentPlayer, char player1, char player2);
    void initializeBoard();
    void clearBoard();
    void printBoard();
    void displayLogo();
    char _board[3][3];
};

#endif /* TICTACTOEGAME_HPP_ */
