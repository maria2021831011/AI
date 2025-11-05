#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char,int>>> adj;
map<char, bool> vis;
char en;

void ucs(char start) {
    // priority_queue: pair<cost, path>
    priority_queue<pair<int, vector<char>>,
                   vector<pair<int, vector<char>>>,
                   greater<pair<int, vector<char>>>> pq;

    pq.push({0, vector<char>{start}}); // initial cost 0, path with start

    while (!pq.empty()) {
        int cost = pq.top().first;
        vector<char> path = pq.top().second;
        pq.pop();

        char node = path.back();

        if (vis[node]) continue;
        vis[node] = true;

        cout << node << " " << cost << endl;

        if (node == en) {
            cout << "Path: ";
            for (char c : path) cout << c;
            cout << "\nTotal cost: " << cost << endl;
            return;
        }

        for (auto v : adj[node]) {
            char next = v.first;
            int w = v.second;
            if (!vis[next]) {
                vector<char> new_path = path;
                new_path.push_back(next);
                pq.push({cost + w, new_path});
            }
        }
    }

    cout << "Not found\n";
}

int main() {
    int n, w;
    cin >> n;

    char start;
    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    cin >> start >> en;

    cout << "UCS traversal:\n";
    ucs(start);

    return 0;
}

