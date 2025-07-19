 #include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard() {
    char pos = '1';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = pos++;
}

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;
    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

bool makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken! Try again.\n";
        return false;
    } else {
        board[row][col] = currentPlayer;
        return true;
    }
}

int main() {
    char playAgain;

    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while(!gameOver) {
            displayBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            cin >> move;

            if(move < 1 || move > 9) {
                cout << "Invalid move! Enter 1-9.\n";
                continue;
            }

            if(makeMove(move)) {
                if(checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if(isDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
