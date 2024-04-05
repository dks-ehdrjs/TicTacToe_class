#include<iostream>

using namespace std;

class BingoGame {
public:
    char board[3][3];
    char currentPlayer;
    bool gameFinished;

    BingoGame();

    void resetBoard();

    void printBoard() const;

    bool placeMark(int row, int col);

    char checkWinner() const;

    void play();
};
