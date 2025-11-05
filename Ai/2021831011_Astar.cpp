/*7
A B 2
A C 3
B D 4
C E 2
D F 3
E F 2
F G 1
7
A 7
B 6
C 4
D 6
E 2
F 1
G 0
A
G
*/
/*
#include<bits/stdc++.h>
using namespace std;
map<char,vector<pair<char,int>>>graph;
map<char,int>heuristic;
char goal;
void aStar(char start){
    typedef pair<int,vector<char>>el;
    priority_queue<el,vector<el>,greater<el>>pq;
    map<char,bool>visited;
    map<char,int>g;
    g[start]=0;
    vector<char>init;
    init.push_back(start);
    pq.push(make_pair(heuristic[start],init));
    while(!pq.empty()){
        el top=pq.top();
        pq.pop();
        int f_cost=top.first;
        vector<char>path=top.second;
        char current=path.back();
        if(visited[current])continue;
        visited[current]=true;
        cout<<"Visiting: "<<current<<" with f = "<< f_cost<<endl;
        if(current==goal){
            cout<<"\n Goal Reached! Path: ";
            for(char node:path)cout<<node<<" ";
            cout<<"\nTotal cost: "<<g[current]<<endl;
            return;
        }
        for(int i=0;i<graph[current].size();i++){
            char neighbor=graph[current][i].first;
            int cost=graph[current][i].second;
            if(!visited[neighbor]){
                int new_g=g[current]+cost;
                int new_f=new_g+heuristic[neighbor];
                if(!g.count(neighbor)||new_g<g[neighbor]){
                    g[neighbor]=new_g;
                    vector<char> new_path=path;
                    new_path.push_back(neighbor);
                    pq.push(make_pair(new_f,new_path));
                }
            }
        }
    }

    cout<<" Goal not reachable.\n";
}
int main(){
    int ed;
    cout<<"Enter edges:";
    cin>>ed;
    cout<<"Enter edges(e.g. A B 3):\n";
    for(int i=0;i<ed;i++){
        char u, v;
        int cost;
        cin>>u>>v>>cost;
        graph[u].push_back(make_pair(v,cost));
        graph[v].push_back(make_pair(u,cost));
    }
    int hv;
    cout<<"\nEnter heuristic values: ";
    cin>>hv;
    cout<<"Enter heuristics (e.g. A 5):\n";
    for(int i=0;i<hv;i++){
        char node;
        int h;
        cin>>node>>h;
        heuristic[node]=h;
    }

    char start;
    cout<<"\nEnter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    cout<<"\n A* Search Path:\n";
    aStar(start);
    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char, int>>> adj;
map<char, bool> vis;
map<char, int> h; // heuristic
char goal;

void aStar(char start) {
    priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<pair<int, vector<char>>>> pq;
    map<char, int> g; // actual cost

    pq.push({h[start], {start}});
    g[start] = 0;

    while (!pq.empty()) {



        int f = pq.top().first;
        vector<char> path = pq.top().second;
        char u = path.back();

        if (vis[u]) continue;
        vis[u] = true;

        cout << "Visiting: " << u << " (f=" << f << ")\n";

        if (u == goal) {
            cout << "\nGoal Reached!\nPath: ";
            for (char c : path) cout << c << " ";
            cout << "\nTotal cost: " << g[u] << endl;
            return;
        }

        for (auto it : adj[u]) {
            char v = it.first;
            int cost = it.second;
            if (!vis[v]) {
                int new_g = g[u] + cost;
                int new_f = new_g + h[v];
                if (!g.count(v) || new_g < g[v]) {
                    g[v] = new_g;
                    auto new_path = path;
                    new_path.push_back(v);
                    pq.push({new_f, new_path});
                }
            }
        }
    }
    cout << "Goal not reachable.\n";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        vis[u] = vis[v] = false;
    }

    int hn;
    cin >> hn;
    for (int i = 0; i < hn; i++) {
        char node;
        int val;
        cin >> node >> val;
        h[node] = val;
    }

    char start;
    cin >> start >> goal;

    cout << "\nA* Traversal:\n";
    aStar(start);
}

/*
#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char,int>>> graph;
map<char,int> heuristic;
char goal;

void aStar(char start) {
    priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<>> pq;
    map<char,bool> visited;
    map<char,int> g;

    g[start] = 0;
    pq.push({heuristic[start], {start}});

    while(!pq.empty()) {
       pair<int, vector<char>> top = pq.top();
pq.pop();
int f_cost = top.first;
vector<char> path = top.second;

char current = path.back();
;

        if(visited[current]) continue;
        visited[current] = true;

        cout << "Visiting: " << current << " with f = " << f_cost << endl;

        if(current == goal) {
            cout << "\nGoal Reached! Path: ";
            for(char node : path) cout << node << " ";
            cout << "\nTotal cost: " << g[current] << endl;
            return;
        }

    for(int i = 0; i < graph[current].size(); i++) {
    char neighbor = graph[current][i].first;
    int cost = graph[current][i].second;

            if(!visited[neighbor]) {
                int new_g = g[current] + cost;
                int new_f = new_g + heuristic[neighbor];
                if(!g.count(neighbor) || new_g < g[neighbor]) {
                    g[neighbor] = new_g;
                    auto new_path = path;
                    new_path.push_back(neighbor);
                    pq.push({new_f, new_path});
                }
            }
        }
    }

    cout << "Goal not reachable.\n";
}

int main() {
    int edges, h_values;
    char start;

    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (node1 node2 cost):\n";
    for(int i = 0; i < edges; i++) {
        char u, v; int cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    cout << "Enter number of heuristic values: ";
    cin >> h_values;
    cout << "Enter heuristics (node value):\n";
    for(int i = 0; i < h_values; i++) {
        char node; int h;
        cin >> node >> h;
        heuristic[node] = h;
    }

    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;

    cout << "\nA* Search Path:\n";
    aStar(start);

    return 0;
}
*/
