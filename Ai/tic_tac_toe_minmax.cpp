#include<bits/stdc++.h>
using namespace std;
char maria[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
const char h='X';
const char ai='O';
void pb(){
    cout<<"\n";
    for(int i=0;i<3;i++){
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<maria[i][j];
            if(j<2)cout<<" | ";
        }
        cout<<"\n";
        if(i<2)cout<<"---+---+---\n";
    }
    cout<<"\n";
}
bool ml(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(maria[i][j]!=h&&maria[i][j]!=ai)
                return true;
    return false;
}
int ev(){
    for(int i=0;i<3;i++){
        if(maria[i][0]==maria[i][1]&&maria[i][1]==maria[i][2]){
            return(maria[i][0]==ai)?10:(maria[i][0]==h?-10:0);
        }
    }
    for(int j=0;j<3;j++){
        if(maria[0][j]==maria[1][j]&&maria[1][j]==maria[2][j]){
            return(maria[0][j]==ai)?10:(maria[0][j]==h?-10:0);
        }
    }
    if(maria[0][0]==maria[1][1]&&maria[1][1]==maria[2][2]){
        return(maria[0][0]==ai)?10:(maria[0][0]==h?-10:0);
    }
    if(maria[0][2]==maria[1][1]&&maria[1][1]==maria[2][0]){
        return(maria[0][2]==ai)?10:(maria[0][2]==h?-10:0);
    }
    return 0;
}

int minimax(int depth,bool isMax,int alpha,int beta){
    int score=ev();
    if(score==10)return score-depth;
    if(score==-10)return score+depth;
    if(!ml())return 0;
    if(isMax){
        int best=numeric_limits<int>::min();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(maria[i][j]!=h&&maria[i][j]!=ai){
                    char backup=maria[i][j];
                    maria[i][j]=ai;
                    best=max(best,minimax(depth+1,false,alpha, beta));
                    maria[i][j]=backup;
                    alpha=max(alpha,best);
                    if(beta<=alpha)return best;
                }
            }
        }
        return best;
    } else {
        int best=numeric_limits<int>::max();
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(maria[i][j]!=h&&maria[i][j]!=ai){
                    char backup=maria[i][j];
                    maria[i][j]=h;
                    best=min(best,minimax(depth+1,true,alpha,beta));
                    maria[i][j]=backup;
                    beta=min(beta,best);
                    if(beta<=alpha)return best;
                }
            }
        }
        return best;
    }
}

pair<int,int>fm(){
    int bestVal=numeric_limits<int>::min();
    pair<int,int>bestMove={-1,-1};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(maria[i][j]!=h&&maria[i][j]!=ai){
                char backup=maria[i][j];
                maria[i][j]=ai;
                int moveVal=minimax(0,false,numeric_limits<int>::min(),numeric_limits<int>::max());
                maria[i][j]=backup;
                if(moveVal>bestVal){
                    bestMove={i,j};
                    bestVal=moveVal;
                }
            }
        }
    }
    return bestMove;
}

char ck(){
    int score=ev();
    if(score==10)return ai;
    else if(score==-10) return h;
    else if(!ml())return 'D';
    return 'N';
}

void ht(){
    int move;
    while(true){
        cout<<"Enter your move(1-9): ";
        cin>>move;
        if(cin.fail()||move<1||move>9){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Try again.\n";
            continue;
        }
        int row=(move-1)/3;
        int col=(move-1)%3;
        if(maria[row][col]!=h&&maria[row][col]!=ai){
            maria[row][col]=h;
            break;
        } else{
            cout<<" Try again.\n";
        }
    }
}

int main(){
    cout<<"Tic Tac Toe - You are X, AI is O\n";
    pb();
    while(true){
        ht();
        pb();
        char result=ck();
        if(result==h){cout<<"Congratulations!\n";break;}
        else if(result=='D'){cout<<"It's a draw!\n";break; }
        cout<<"Ai  move...\n";
        pair<int,int>aiMove=fm();
        if(aiMove.first!=-1)maria[aiMove.first][aiMove.second]=ai;
        pb();
        result=ck();
        if(result==ai){cout<<"Ai wins! Better.\n"; break;}
        else if(result=='D'){cout<<"It's a draw!\n"; break;}
    }
    return 0;
}

