#include <iostream>
#include <limits>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

const char HUMAN = 'X';
const char AI = 'O';

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool movesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != HUMAN && board[i][j] != AI)
                return true;
    return false;
}

int evaluate() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return (board[i][0]==AI) ? 10 : (board[i][0]==HUMAN ? -10 : 0);
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return (board[0][i]==AI) ? 10 : (board[0][i]==HUMAN ? -10 : 0);
    }
    // Check diagonals
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return (board[0][0]==AI) ? 10 : (board[0][0]==HUMAN ? -10 : 0);
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return (board[0][2]==AI) ? 10 : (board[0][2]==HUMAN ? -10 : 0);
    return 0;
}

int minimax(bool isMax) {
    int score = evaluate();
    if (score == 10) return score;
    if (score == -10) return score;
    if (!movesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != HUMAN && board[i][j] != AI) {
                    char backup = board[i][j];
                    board[i][j] = AI;
                    best = max(best, minimax(false));
                    board[i][j] = backup;
                }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != HUMAN && board[i][j] != AI) {
                    char backup = board[i][j];
                    board[i][j] = HUMAN;
                    best = min(best, minimax(true));
                    board[i][j] = backup;
                }
        return best;
    }
}

pair<int,int> bestMove() {
    int bestVal = -1000;
    pair<int,int> move = {-1, -1};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != HUMAN && board[i][j] != AI) {
                char backup = board[i][j];
                board[i][j] = AI;
                int moveVal = minimax(false);
                board[i][j] = backup;
                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    move = {i, j};
                }
            }
    return move;
}

char checkWinner() {
    int score = evaluate();
    if (score == 10) return AI;
    if (score == -10) return HUMAN;
    if (!movesLeft()) return 'D';
    return 'N';
}

void humanTurn() {
    int move;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        if (cin.fail() || move < 1 || move > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }
        int r = (move - 1) / 3;
        int c = (move - 1) % 3;
        if (board[r][c] != HUMAN && board[r][c] != AI) {
            board[r][c] = HUMAN;
            break;
        } else {
            cout << "That cell is already taken!\n";
        }
    }
}

int main() {
    cout << "Tic Tac Toe (You = X, AI = O)\n";
    printBoard();

    while (true) {
        humanTurn();
        printBoard();

        char res = checkWinner();
        if (res == HUMAN) { cout << "You win!\n"; break; }
        if (res == 'D') { cout << "It's a draw!\n"; break; }

        cout << "AI is thinking...\n";
        pair<int,int> aiMove = bestMove();
        if (aiMove.first != -1)
            board[aiMove.first][aiMove.second] = AI;
        printBoard();

        res = checkWinner();
        if (res == AI) { cout << "AI wins!\n"; break; }
        if (res == 'D') { cout << "It's a draw!\n"; break; }
    }

    return 0;
}

