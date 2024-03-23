#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "-------------\n";
    for(int i = 0; i < 3; ++i) {
        cout << "| ";
        for(int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if the game is won
bool checkWin(char board[3][3], char player) {
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard(board);

    do {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row-1][col-1] = currentPlayer;
        displayBoard(board);

        // Check for win
        if(checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
        }
        // Check for draw
        else if(checkDraw(board)) {
            cout << "It's a draw!\n";
            gameDraw = true;
        }
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while(!gameWon && !gameDraw);

    cout << "Thanks for playing!\n";

    return 0;
}
