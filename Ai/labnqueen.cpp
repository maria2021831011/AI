#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bd;
int n;
int sol = 0;

bool check(int r,int c){
    for(int i=0;i<r;i++)
        if(bd[i][c]==1) return false;
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        if(bd[i][j]==1) return false;
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        if(bd[i][j]==1) return false;
    return true;
}

void solve(int row){
    if(row==n){
        sol++;
        cout << "Solution " << sol << ":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << (bd[i][j] ? "Q" : ".") << " ";
            cout << endl;
        }
        cout << "Queen positions:\n";
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(bd[i][j])
                    cout << i+1 << "->" << j+1 << endl;
        cout << endl;
        return;
    }

    for(int col=0;col<n;col++){
        if(check(row,col)){
            bd[row][col]=1;
            solve(row+1);
            bd[row][col]=0;
        }
    }
}

int main(){
    cin >> n;
    bd.assign(n, vector<int>(n,0));
    solve(0);
    cout << "Total solutions: " << sol << endl;
}








/*
int n;
vector<vector<int>> bd;
int sol = 0;

bool safe(int row, int col) {
    for(int i=0;i<row;i++)
        if(bd[i][col]==1) return false;

    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        if(bd[i][j]==1) return false;

    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        if(bd[i][j]==1) return false;

    return true;
}

void sole(int row) {
    if(row==n) {
        sol++;
        cout << "Solution " << sol << ":\n";

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << (bd[i][j] ? "Q" : ".") << " ";
            cout << endl;
        }

        cout << "Queen positions: ";
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(bd[i][j])
                    cout << "(" << i+1 << "," << j+1 << ") ";
        cout << "\n\n";
        return;
    }

    for(int col=0;col<n;col++){
        if(safe(row,col)){
            bd[row][col]=1;
            sole(row+1);
            bd[row][col]=0;
        }
    }
}

int main() {
    cin >> n;
    bd.assign(n, vector<int>(n,0));
    sole(0);
    cout << "Total solutions: " << sol << endl;
}
*/
