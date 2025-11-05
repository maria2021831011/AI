#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
map<char, bool> vis;
char en;

// Depth-Limited Search
bool dls(char u, int depth, int limit) {
    if (depth > limit) return false;

    vis[u] = true;
    cout << u << "->";

    if (u == en) {
        cout << "\nReached " << en << " at depth " << depth << endl;
        return true;
    }

    for (char v : adj[u]) {
        if (!vis[v]) {
            if (dls(v, depth + 1, limit)) return true;
        }
    }

    return false;
}

// Iterative Deepening Search
void ids(char start, int maxd) {
    for (int depth = 0; depth <= maxd; depth++) {
        // reset visited
        for (auto &p : vis) p.second = false;

        cout << "\nTrying depth = " << depth << endl;
        if (dls(start, 0, depth)) return;
    }

    cout << "Did not find " << en << " within max depth " << maxd << endl;
}

int main() {
    int n;
    cin >> n;               // number of edges

    char st;
    int maxd;
    cin >> st >> en >> maxd;

    // read edges
    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u] = vis[v] = false;
    }

    ids(st, maxd);

    return 0;
}
