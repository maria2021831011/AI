#include<bits/stdc++.h>
using namespace std;
map<char,vector<pair<char,int>>>adj;
map<char,bool>vis;
char en;
void ucs(char start)
{
    priority_queue<pair<int,vector<char>>,vector<pair<int,vector<char>>>,greater<pair<int,vector<char>>>>pq;
      pq.push({0, vector<char>{start}});
    while(!pq.empty())
    {
        int c=pq.top().first;
        vector<char>path=pq.top().second;
        pq.pop();
         char node = path.back();
         if(vis[node])continue;
        vis[node] = true;
        cout<<node<<" "<<c<<endl;
        if (node ==en) {
            cout << "Path: ";
            for (char p : path) cout << p;
            cout << "\nTotal cost: " << c << endl;
            return;
        }
        for(auto v:adj[node]){
            char nu=v.first;
            int nc=v.second;
            if(!vis[nu]){
                vector<char>np=path;
                np.push_back(nu);
                pq.push({+c,np});

            }



        }
    }cout<<"no"<<endl;
}

int main()
{
    int n,cost;
    cin >> n;
    char st;
    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});

    }
       cin >> st >> en ;

    ucs(st);

    return 0;
}


