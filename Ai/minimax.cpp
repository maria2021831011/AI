#include<bits/stdc++.h>
using namespace std;
char BOARD[3][3];
const char AI='X';
const char HU='O';

void print(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
{
   cout<<(BOARD[i][j]== ' '?'_':BOARD[i][j]);
   if(j<2)cout<<'|';
}cout<<endl;
}cout<<endl;

}
bool movef() {
    for (auto &r : BOARD)
        for (auto c : r)
            if (c == ' ') return true;
    return false;
}


int evaluate() {
    for (int i = 0; i < 3; i++) {
        // Columns
        if (BOARD[0][i] == BOARD[1][i] && BOARD[1][i] == BOARD[2][i] && BOARD[0][i] != ' ') {
            if (BOARD[0][i] == AI) return +10;
            if (BOARD[0][i] == HU) return -10;
        }
        // Rows
        if (BOARD[i][0] == BOARD[i][1] && BOARD[i][1] == BOARD[i][2] && BOARD[i][0] != ' ') {
            if (BOARD[i][0] == AI) return +10;
            if (BOARD[i][0] == HU) return -10;
        }
    }

    // Diagonals
    if (BOARD[0][0] == BOARD[1][1] && BOARD[1][1] == BOARD[2][2] && BOARD[0][0] != ' ') {
        if (BOARD[0][0] == AI) return +10;
        if (BOARD[0][0] == HU) return -10;
    }
    if (BOARD[0][2] == BOARD[1][1] && BOARD[1][1] == BOARD[2][0] && BOARD[0][2] != ' ') {
        if (BOARD[0][2] == AI) return +10;
        if (BOARD[0][2] == HU) return -10;
    }

    return 0;
}

int minimax(bool issafe,int al,int be)
{
    int s=evaluate();
    if(s==10||s==-10)return s;
    if(!movef())return 0;
    if(issafe){
        int bestval=-10000;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(BOARD[i][j]==' '){
            BOARD[i][j]=AI;
            bestval=max(bestval,minimax(false,al,be));
            BOARD[i][j]=' ';
            al=max(bestval,al);
            if(be<=al)return bestval;


    }}}return bestval;}else{

    int bestval=10000;

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(BOARD[i][j]==' '){
            BOARD[i][j]=HU;
            bestval=min(bestval,minimax(true,al,be));
            BOARD[i][j]=' ';
            be=min(be,bestval);
            if(be<=al)return bestval;

    }
    }}
    return bestval;
}}

pair<int,int>bestm()
{int bestval=-10000;
pair<int,int>mv={-1,-1};
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(BOARD[i][j]==' '){
            BOARD[i][j]=AI;
            int val=minimax(false,-10000,10000);
            BOARD[i][j]=' ';
            if(val>bestval){
            bestval=val;
            mv={i,j};
        }
    }
}

}return mv;
}

int main(){for(auto &r:BOARD)fill(begin(r),end(r),' ');
print();
while(true){

    int mv;
    cin>>mv;
    int r=(mv-1)/3,c=(mv-1)%3;
    if(mv<1||mv>9||BOARD[r][c]!=' '){cout<<" no valid"<<endl;continue;}
      BOARD[r][c]='O';
      print();
    if(evaluate()==-10){cout<<"winning human"<<endl;break;}
    if(!movef()){cout<<"draw "<<endl;break;}


    cout<<"AI GENERATE"<<endl;
    pair<int ,int>gen=bestm();
    int i=gen.first;
    int j=gen.second;
    BOARD[i][j]='X';
    print();
      if(evaluate()==10){cout<<"winning computer"<<endl;break;}
    if(!movef()){cout<<"draw "<<endl;break;}
}
}











/*#include <bits/stdc++.h>
using namespace std;

char board[3][3];
const char HUMAN = 'X', AI = 'O';

// Print board
void printBoard() {
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << (board[i][j]==' ' ? '_' : board[i][j]);
            if(j<2) cout<<"|";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// Check for win
int evaluate() {
    // Rows & columns
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if(board[i][0]==AI) return +10;
            if(board[i][0]==HUMAN) return -10;
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            if(board[0][i]==AI) return +10;
            if(board[0][i]==HUMAN) return -10;
        }
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]==AI) return +10;
        if(board[0][0]==HUMAN) return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][2]==AI) return +10;
        if(board[0][2]==HUMAN) return -10;
    }
    return 0;
}

// Check moves left
bool movesLeft() {
    for(auto &r: board)
        for(char c:r)
            if(c==' ') return true;
    return false;
}

// Minimax with alpha-beta
int minimax(bool isMax, int alpha, int beta) {
    int score = evaluate();
    if(score==10 || score==-10) return score;
    if(!movesLeft()) return 0;

    if(isMax){
        int best=-1000;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' '){
                    board[i][j]=AI;
                    best = max(best, minimax(false, alpha, beta));
                    board[i][j]=' ';
                    alpha = max(alpha,best);
                    if(beta<=alpha) return best;
                }
        return best;
    } else {
        int best=1000;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' '){
                    board[i][j]=HUMAN;
                    best = min(best, minimax(true, alpha, beta));
                    board[i][j]=' ';
                    beta = min(beta,best);
                    if(beta<=alpha) return best;
                }
        return best;
    }
}

// Best AI move
pair<int,int> bestMove() {
    int bestVal=-1000;
    pair<int,int> move = {-1,-1};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' '){
                board[i][j]=AI;
                int val = minimax(false, -1000, 1000);
                board[i][j]=' ';
                if(val>bestVal){
                    bestVal=val;
                    move={i,j};
                }
            }
    return move;
}

// Main game
int main() {
    for(auto &r:board) fill(begin(r), end(r),' ');
    printBoard();
    while(true){
        int pos;
        cout<<"Enter position (1-9): ";
        cin>>pos;
        int r=(pos-1)/3, c=(pos-1)%3;
        if(pos<1||pos>9 || board[r][c]!=' '){ cout<<"Invalid!\n"; continue;}
        board[r][c]=HUMAN;
        printBoard();
        if(evaluate()==-10){ cout<<"You win!\n"; break;}
        if(!movesLeft()){ cout<<"Draw!\n"; break;}

        cout<<"AI is thinking...\n";
        pair<int,int>het=bestMove();
        int i=het.first;
        int j=het.second;
        board[i][j]=AI;
        printBoard();
        if(evaluate()==10){ cout<<"AI wins!\n"; break;}
        if(!movesLeft()){ cout<<"Draw!\n"; break;}
    }
}*/
