#include<bits/stdc++.h>
using namespace std;
map<char,vector<char>>adj;
char target;
bool found=false;
bool dls(char u,int depth,int limit, map<char,bool>&vis){
    if (depth>limit)return false;
    vis[u]=true;
    cout<<u <<"->"<<" ";
    if(u==target){
        cout<<"\nReach" <<target <<" at depth " <<depth <<endl;
        return true;
    }
    for(char v:adj[u]){
        if(!vis[v]){
            if(dls(v, depth + 1, limit, vis)) return true;
        }
    }

    return false;
}
void ids(char start,int maxd){
    for (int depth=0; depth<=maxd;depth++){
        cout<<"\nTrying= " <<depth<<endl;
        map<char, bool> vis;
        for(auto& pair:adj)vis[pair.first]=false;
        if(dls(start,0,depth,vis)){
            found=true;
            return;
        }
    }

    cout<<"\nDid not reach " <<target<<" within depth"<<maxd<< endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    char start,en;
    int maxd;
    cin>>start>>en>>maxd;
    target=en;
    cout<<"IDS :"<<maxd<<":\n";
    ids(start,maxd);
    return 0;
}
/*input
14
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
A O 4*/

