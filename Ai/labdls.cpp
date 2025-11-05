
#include<bits/stdc++.h>
using namespace std;
map<char,vector<char>>adj;
map<char,bool>vis;
char target;
bool found=false;
void dls(char u, int depth, int limit){
    if (depth > limit || found)return;
    vis[u]=true;
    cout << u <<"->"<< " ";
    if(u==target){
        found = true;
        cout<<"\nReached " <<target <<" at depth "<<depth<<endl;
        return;
    }
    for(char v:adj[u]){
        if (!vis[v]){
            dls(v, depth + 1,limit);
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
    char start,target;
    int limit;
    cin >>start>>target>>limit;
    cout<<"DLS "<<limit<<": ";
    dls(start, 0,limit);
    if(!found)
        cout<<"\nDid not reach " <<target <<" within depth "<<limit<<endl;

    return 0;
}
