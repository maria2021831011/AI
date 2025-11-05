//recursive based
 #include<bits/stdc++.h>
using namespace std;
map<char,vector<char>>adj;
map<char,bool>vis;
bool found=false;
char target;

void dfs(char u){
    if(found)return;
    vis[u]=true;
    cout<<u <<"->"<<" ";
    if(u==target){
        found=true;
        return;
    }
    for(char v:adj[u]){
        if (!vis[v]){
            dfs(v);
            if(found)return;
        }
    }
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
    cout<<endl;
    if(found)
        cout<<"Reached node "<<en<< endl;
    else
        cout<< "Did not reach node " <<en<< endl;

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
