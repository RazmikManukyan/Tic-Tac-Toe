#include <iostream>
#include <vector>

std::vector<std::vector<char>> board(3, std::vector(3, ' '));

void printBoard() {
    std::cout << "-------------" << std::endl;
    for(int i = 0; i < 3; ++i) {
        std::cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << std::endl;
        std::cout << "-------------" << std::endl;
    }
}

bool checkWinner(char player) {
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';

    while(true) {
        printBoard();

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if(checkWinner(currentPlayer)) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
                break;
            }

            if(isBoardFull()) {
                printBoard();
                std::cout << "It's a draw! Better luck nex time!" << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
