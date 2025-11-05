#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
map<char, bool> vis;
char en;

bool dfs(char start) {
    stack<char> st;       // create a stack for DFS
    st.push(start);       // push the starting node onto the stack
    vis[start] = true;    // mark start as visited

    while (!st.empty()) {
        char u = st.top();
        st.pop();
        cout << u << " "; // print node as visited

        if (u == en) return true; // reached target

        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
    char v = *it;
    if (!vis[v]) {
        vis[v] = true;
        st.push(v);
    }
}

    }
    return false; // target not reached
}

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u] = vis[v] = false;
    }

    char start;
    cin >> start >> en;

    if (dfs(start))
        cout << "\nReach\n";
    else
        cout << "\nNot Reach\n";
}

