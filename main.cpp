//============================================================================
// Name        : TicTacToe.cpp
// Author      : Joey Norkin
// Description : Tic Tac Toe!
//============================================================================

#include <iostream>
#include <TicTacToeGame.cpp>

using namespace std;

int main() {
    char input;
    bool playAgain = true;

    TicTacToeGame game;

    do {
        game.playGame();
        cout << "Would you like to play again? (Y/n): ";
        cin >> input;
        if (input == 'N' || input == 'n') {
            playAgain = false;
        }
    } while (playAgain);

    return 0;
}
