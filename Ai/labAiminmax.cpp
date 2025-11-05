#include<bits/stdc++.h>
using namespace std;
const char H='x';
const char AI='o';

char bd[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void print()
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<bd[i][j];
            if(j<2)cout<<" | ";
        }cout<<endl;
        if(i<2)cout<<"---+---+---"<<endl;

    }
       cout<<endl;
}
int eq(){
for(int i=0;i<3;i++)
{
    if(bd[i][0]==bd[i][1]&&bd[i][1]==bd[i][2]){
            if(bd[i][0]==AI)return 10;
            if(bd[i][0]==H)return -10;

    }
    if(bd[0][i]==bd[1][i]&&bd[1][i]==bd[2][i]){
            if(bd[0][i]==AI)return 10;
            if(bd[0][i]==H)return -10;

    }
}

if(bd[0][0]==bd[1][1]&&bd[1][1]==bd[2][2]){
            if(bd[0][0]==AI)return 10;
            if(bd[0][0]==H)return -10;

    }
    if(bd[2][0]==bd[1][1]&&bd[1][1]==bd[0][2]){
            if(bd[2][0]==AI)return 10;
            if(bd[2][0]==H)return -10;

    }
    return 0;

}
bool movef(){

 for (auto &r : bd)
        for (auto &c : r)
        if(c!=AI&&c!=H)return true;


return false;

}
int minmax(bool ifsafe,int al,int be,int d){
int s=eq();
if(s==10)return s-d;
if(s==-10)return s+d;
if(!movef())return 0;
if(ifsafe){int best=INT_MIN;

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
            if(bd[i][j]!=AI&&bd[i][j]!=H){
        char backup=bd[i][j];
        bd[i][j]=AI;
        best=max(best,minmax(false,al,be,d+1));
        bd[i][j]=backup;
        al=max(al,best);
        if(be<=al)return best;

}

}
}return best;}else{
int best=INT_MAX;

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
            if(bd[i][j]!=AI&&bd[i][j]!=H){
        char backup=bd[i][j];
        bd[i][j]=H;
        best=min(best,minmax(true,al,be,d+1));
        bd[i][j]=backup;
        be=min(be,best);
        if(be<=al)return best;


            }}}return best;}

}
pair<int,int>findmove(){int best=INT_MIN;
pair<int,int>bestm={-1,-1};
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
            if(bd[i][j]!=AI&&bd[i][j]!=H){
        char backup=bd[i][j];
        bd[i][j]=AI;
        int val=minmax(false,INT_MIN,INT_MAX,0);
        bd[i][j]=backup;
        if(val>best){
            best=val;
            bestm={i,j};
        }}
    }
}return bestm;
}

void human(){

int m;
while(true){
    cout<<"enter 1-9 move"<<endl;
    cin>>m;
    if(m<1||m>9||cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<endl;
        cout<<"try again"<<endl;
        continue;
    }int r=(m-1)/3,c=(m-1)%3;
    if(bd[r][c]!=AI&&bd[r][c]!=H){
        bd[r][c]=H;
        break;
    }else{
    cout<<"try again"<<endl;
    }
    }
}
char check()
{
    int s=eq();
    if(s==10)return AI;
    if(s==-10)return H;
    if(!movef())return 'D';
    return 'N';
}


int main()
{
    cout<<"tic tac toe"<<endl;
    print();
    while(true)
    {
        human();
        print();
        char res=check();
        if(res==H){cout<<"win human"<<endl;break;}
        if(res=='D'){cout<<"draw"<<endl;break;}
        cout<<"ai thingking.........."<<endl;
        pair<int,int>bestmove=findmove();
        int x=bestmove.first;
        int y=bestmove.second;
        if(x!=-1)bd[x][y]=AI;
        print();
          res=check();
        if(res==AI){cout<<"win ai"<<endl;break;}
        if(res=='D'){cout<<"draw"<<endl;break;}   }
        return 0;
}



/*#include <bits/stdc++.h>
using namespace std;

const char HUMAN = 'X';
const char AI = 'O';

char bd[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void printBoard() {
    cout << "\n";
    for (int i=0;i<3;i++) {
        cout << " ";
        for (int j=0;j<3;j++) {
            cout << bd[i][j];
            if (j<2) cout << " | ";
        }
        cout << "\n";
        if (i<2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool movesLeft() {
    for (auto &r : bd)
        for (auto &c : r)
            if (c != HUMAN && c != AI) return true;
    return false;
}

int evaluate() {
    // rows and columns
    for (int i=0;i<3;i++) {
        if (bd[i][0] == bd[i][1] && bd[i][1] == bd[i][2]) {
            if (bd[i][0] == AI) return 10;
            if (bd[i][0] == HUMAN) return -10;
        }
        if (bd[0][i] == bd[1][i] && bd[1][i] == bd[2][i]) {
            if (bd[0][i] == AI) return 10;
            if (bd[0][i] == HUMAN) return -10;
        }
    }
    // diagonals
    if (bd[0][0] == bd[1][1] && bd[1][1] == bd[2][2]) {
        if (bd[0][0] == AI) return 10;
        if (bd[0][0] == HUMAN) return -10;
    }
    if (bd[0][2] == bd[1][1] && bd[1][1] == bd[2][0]) {
        if (bd[0][2] == AI) return 10;
        if (bd[0][2] == HUMAN) return -10;
    }
    return 0;
}

// minimax with alpha-beta pruning; depth used to prefer faster wins/slower losses
int minimax(bool isMax, int alpha, int beta, int depth) {
    int score = evaluate();
    if (score == 10) return score - depth;   // AI win
    if (score == -10) return score + depth;  // Human win
    if (!movesLeft()) return 0;               // draw

    if (isMax) {
        int best = INT_MIN;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (bd[i][j] != HUMAN && bd[i][j] != AI) {
                    char backup = bd[i][j];
                    bd[i][j] = AI;
                    best = max(best, minimax(false, alpha, beta, depth+1));
                    bd[i][j] = backup;
                    alpha = max(alpha, best);
                    if (beta <= alpha) return best; // prune
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (bd[i][j] != HUMAN && bd[i][j] != AI) {
                    char backup = bd[i][j];
                    bd[i][j] = HUMAN;
                    best = min(best, minimax(true, alpha, beta, depth+1));
                    bd[i][j] = backup;
                    beta = min(beta, best);
                    if (beta <= alpha) return best; // prune
                }
            }
        }
        return best;
    }
}

pair<int,int> bestMove() {
    int bestVal = INT_MIN;
    pair<int,int> mv = {-1,-1};
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (bd[i][j] != HUMAN && bd[i][j] != AI) {
                char backup = bd[i][j];
                bd[i][j] = AI;
                int val = minimax(false, INT_MIN, INT_MAX, 0);
                bd[i][j] = backup;
                if (val > bestVal) {
                    bestVal = val;
                    mv = {i,j};
                }
            }
        }
    }
    return mv;
}

char checkWinner() { // returns 'X' or 'O' for winner, 'D' for draw, 'N' for none
    int s = evaluate();
    if (s == 10) return AI;
    if (s == -10) return HUMAN;
    if (!movesLeft()) return 'D';
    return 'N';
}

void humanTurn() {
    int m;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> m;
        if (cin.fail() || m < 1 || m > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, try again.\n";
            continue;
        }
        int r = (m-1)/3, c = (m-1)%3;
        if (bd[r][c] != HUMAN && bd[r][c] != AI) {
            bd[r][c] = HUMAN;
            break;
        } else {
            cout << "Cell occupied! Try another.\n";
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
        if (res == 'D') { cout << "Draw!\n"; break; }

      cout << "AI thinking...\n";
pair<int,int> p = bestMove();
int x = p.first;
int y = p.second;
if (x != -1) bd[x][y] = AI;
printBoard();

        res = checkWinner();
        if (res == AI) { cout << "AI wins!\n"; break; }
        if (res == 'D') { cout << "Draw!\n"; break; }
    }
    return 0;
}*/
