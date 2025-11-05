#include<bits/stdc++.h>
using namespace std;
map<char, vector<char>> adj;
map<char, bool> vis;
map<char, int> level;
map<char, char> parent;
char target;

void bfs(char start) {
    queue<char> q;
    q.push(start);
    vis[start] = true;
    level[start] = 0;
    parent[start] = '\0';

    map<int, vector<char>> level_nodes;

    while (!q.empty()) {
        char u = q.front();
        q.pop();
        level_nodes[level[u]].push_back(u);

        for (char v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
    for (auto lv : level_nodes) {
        cout << "At level " << lv.first << ": ";
        for (char node : lv.second) {
            cout << node << " ";
        }
        cout << endl;
    }
    if (vis[target]) {
        cout << "\nReached node " << target << " at level " << level[target] << endl;
        vector<char> path;
        char curr = target;
        while (curr != '\0') {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;

    } else {
        cout << "\nDid not reach node " << target << endl;
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u] = false;
        vis[v] = false;
    }

    char start, end;
    cin >> start >> end;
    target = end;

    bfs(start);

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
