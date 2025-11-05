#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
map<char, bool> vis;
char en;
map<int, vector<char>> ln;
map<char, int> level;
map<char,char>parent;
void bfs(char st) {
    queue<char> q;
    vis[st] = true;
    level[st] = 0;
    parent[st]='\0';
    q.push(st);

    while (!q.empty()) {
        char u = q.front();
        q.pop();
        cout << u << "->";
        ln[level[u]].push_back(u);

        for (char v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                parent[v]=u;
                q.push(v);
                level[v] = level[u] + 1;

            }
        }
    }
}

int main() {
    int n;
    char st;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u] = vis[v] = false;
    }

    cin >> st >> en;
    bfs(st);

    if (level.count(en))
        cout << "\nLevel of " << en << ": " << level[en] << "\n";
    else
        cout << "\nTarget not reachable\n";

    cout << "\n--- Nodes by level ---\n";
    for (auto n : ln) {
        cout << n.first << " -> ";
        for (auto nd : n.second) cout << nd << " ";
        cout << "\n";
    }

    vector<char> path;
    for (char v =en;v!= '\0'; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << "Path from start to " <<en << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];

    }
    cout << "\n";
}

