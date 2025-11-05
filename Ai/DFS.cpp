//stack based
#include<bits/stdc++.h>
using namespace std;
map<char, vector<char>>adj;
map<char,bool>vis;
char target;
void dfs(char start){
    stack<char>s;
    s.push(start);
    vis[start]=true;
    while(!s.empty()){
        char u=s.top();
        s.pop();
        cout<<u<<"->"<<" ";
        if(u == target){
            cout<<"\nReached node "<<target<<endl;
            return;
        }
        for(auto it=adj[u].rbegin();it!=adj[u].rend();++it){
            if(!vis[*it]){
                s.push(*it);
                vis[*it]=true;
            }
        }
    }
    cout <<"\nDid not reach node "<<target<<endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u]=false;
        vis[v]=false;
    }
    char start,en;
    cin>>start>>en;
    target=en;
    cout<<"DFS traversal: ";
    dfs(start);

    return 0;
}

//input
/*14
A B
A C
A D
A E
B F
B G
C H
D I
D J
G K
G L
L O
I M
J N
A O*/
