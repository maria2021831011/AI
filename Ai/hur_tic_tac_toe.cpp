
/*#include <bits/stdc++.h>
using namespace std;

char board[3][3];
const char HUMAN='X', AI='O';

// Print board
void printBoard() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << (board[i][j]==' ' ? '_' : board[i][j]);
            if(j<2) cout<<"|";
        }
        cout << endl;
    }
    cout << endl;
}

// Check winner
char checkWinner() {
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return board[0][i];
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return board[0][2];
    return ' ';
}

// Check moves left
bool movesLeft() {
    for(auto &r:board) for(auto &c:r) if(c==' ') return true;
    return false;
}

// Heuristic AI: win -> block -> center -> corner -> any
pair<int,int> findBestMove() {
    // 1️⃣ Win if possible
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' '){
                board[i][j]=AI;
                if(checkWinner()==AI) return {i,j};
                board[i][j]=' ';
            }
    // 2️⃣ Block human
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' '){
                board[i][j]=HUMAN;
                if(checkWinner()==HUMAN){ board[i][j]=' '; return {i,j}; }
                board[i][j]=' ';
            }
    // 3️⃣ Take center
    if(board[1][1]==' ') return {1,1};
    // 4️⃣ Take corner
    vector<pair<int,int>> corners={{0,0},{0,2},{2,0},{2,2}};
    for(auto c:corners) if(board[c.first][c.second]==' ') return c;
    // 5️⃣ Take any move
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(board[i][j]==' ') return {i,j};
    return {-1,-1};
}

// Main game
int main() {
    for(auto &r:board) fill(begin(r),end(r),' ');
    printBoard();
    while(true){
        int pos;
        cout<<"Enter position (1-9): ";
        cin>>pos;
        if(pos<1 || pos>9) { cout<<"Invalid!\n"; continue; }
        int r=(pos-1)/3, c=(pos-1)%3;
        if(board[r][c]!=' '){ cout<<"Invalid!\n"; continue; }
        board[r][c]=HUMAN;
        printBoard();
        if(checkWinner()==HUMAN){ cout<<"You win!\n"; break; }
        if(!movesLeft()){ cout<<"Draw!\n"; break; }

        cout<<"AI is thinking...\n";
        pair<int,int> ai=findBestMove();
        board[ai.first][ai.second]=AI;
        printBoard();
        if(checkWinner()==AI){ cout<<"AI wins!\n"; break; }
        if(!movesLeft()){ cout<<"Draw!\n"; break; }
    }
}

*/



#include <bits/stdc++.h>
using namespace std;

// --- Global variables ---
char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

const char HUMAN = 'X';
const char AI = 'O';

// --- Print the board ---
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

// --- Check who won the game ---
char checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Row or Column check
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Diagonal check
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}

bool movesLeft() {
    for (auto &r:board)
        for(auto &c:r)
            if (c!= HUMAN && c != AI)
                return true;
    return false;
}

pair<int,int> findBestMove() {
    // 1️⃣ Try to win
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=HUMAN&&board[i][j]!=AI){
                    char backup=board[i][j];
            board[i][j]=AI;

                if(checkWinner()==AI){
                    return {i,j};
                }board[i][j]=backup;
            }
        }
    }

  /*  for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != HUMAN && board[i][j] != AI) {
                char backup = board[i][j];
                board[i][j] = AI;
                if (checkWinner() == AI)
                    return {i, j};
                board[i][j] = backup;
            }
        }
    }
*/
  for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=HUMAN&&board[i][j]!=AI){
                    char backup=board[i][j];
            board[i][j]=HUMAN;

                if(checkWinner()==HUMAN){
                        board[i][j]=backup;
                    return {i,j};
                }board[i][j]=backup;
            }
        }
    }



   /* // 2️⃣ Block human from winning
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != HUMAN && board[i][j] != AI) {
                char backup = board[i][j];
                board[i][j] = HUMAN;
                if (checkWinner() == HUMAN) {
                    board[i][j] = backup;
                    return {i, j};
                }
                board[i][j] = backup;
            }
        }
    }
*/
if(board[1][1]!=HUMAN&&board[1][1]!=AI){
    return {1,1};
}
vector<pair<int,int>>corners={{0,0},{0,2},{2,0},{2,2}};
for(auto c:corners){
    if(board[c.first][c.second]!=HUMAN&&board[c.first][c.second]!=AI){
        return c;
    }
}
  for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != HUMAN && board[i][j] != AI)
                return {i, j};

}}
    return {-1, -1};
    }

    // 3️⃣ Take the center if available
   /* if (board[1][1] != HUMAN && board[1][1] != AI)
        return {1, 1};

    // 4️⃣ Take a corner
    vector<pair<int,int>> corners = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (auto c : corners) {
        if (board[c.first][c.second] != HUMAN && board[c.first][c.second] != AI)
            return c;
    }

    // 5️⃣ Take any remaining move
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != HUMAN && board[i][j] != AI)
                return {i, j};

    return {-1, -1};
}
*/
// --- Main function ---
int main() {
    cout << "Tic Tac Toe Game - Human (X) vs AI (O)\n";
    printBoard();
    while (true) {
        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--;
        int r = move / 3;
        int c = move % 3;

        // Check for invalid move
        if (board[r][c] == HUMAN || board[r][c] == AI) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[r][c] = HUMAN;
        printBoard();
        // Check if human wins
        if (checkWinner() == HUMAN) {
            cout << "🎉 You win!\n";
            break;
        }
        if (!movesLeft()) {
            cout << "🤝 It's a draw!\n";
            break;
        }

        // AI move
        cout << "AI is thinking...\n";
        pair<int,int> aiMove = findBestMove();
        if (aiMove.first != -1)
            board[aiMove.first][aiMove.second] = AI;
        printBoard();

        // Check if AI wins
        if (checkWinner() == AI) {
            cout << "💻 AI wins! Better luck next time.\n";
            break;
        }
        if (!movesLeft()) {
            cout << "🤝 It's a draw!\n";
            break;
        }
    }

    return 0;
}

