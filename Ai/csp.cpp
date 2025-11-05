
#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>>adj;
vector<string>clr;
map<string,string>ans;
bool ok(string u,string c){
    for(auto v:adj[u])
        if(ans[v]==c)return false;
    return true;
}
bool go(vector<string>&ct,int i){
if(i==ct.size())return true;
string u=ct[i];
for(auto &c:clr){
    if(ok(u,c)){
        ans[u]=c;
        if(go(ct,i+1))return true;
        ans[u]=" ";
    }
}return false;
}
int main(){
    int n;
    cin>>n;

   vector<string>ct(n);
   for(int i=0;i<n;i++)
   {

       cin>>ct[i];
   }for(int i=0;i<n;i++){string u;
   cin>>u;
   string v;
        while(cin>>v&&v!="-1"){
            adj[u].push_back(v);
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string c;
        cin>>c;
        clr.push_back(c);
    }

    if(go(ct,0)){
        for(auto u:ct)cout<<u<< " "<<ans[u]<<endl;
        map<string,int>cnt;
        for(auto u:ct)cnt[ans[u]]++;
        for(auto& x:cnt)cout<<x.first<<": "<<x.second<<endl;
    } else cout<<"No\n";
    return 0;
}

