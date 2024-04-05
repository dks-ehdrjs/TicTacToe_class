#include "tictactoe.h"
#include <iostream>

using namespace std;

BingoGame::BingoGame() {
    resetBoard();
    currentPlayer = 'o';
    gameFinished = false;
}

void BingoGame::resetBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

void BingoGame::printBoard() const {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool BingoGame::placeMark(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

char BingoGame::checkWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return '-';
}

void BingoGame::play() {
    while (!gameFinished) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your desired position (e.g., 2 1): ";
        cin >> row >> col;
        if (placeMark(row, col)) {
            char winner = checkWinner();
            if (winner != '-') {
                cout << "Player " << winner << " wins!" << endl;
                gameFinished = true;
            }
            else {
                currentPlayer = (currentPlayer == 'o') ? 'x' : 'o';
            }
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}
