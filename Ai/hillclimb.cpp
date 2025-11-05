#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> puzzle;
    int h;
    string path;
};

vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}};

bool isGoal(const vector<vector<int>>& p) {
    return p == goal;
}

int heuristic(const vector<vector<int>>& p) {
    int dist = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (p[i][j] != 0) {
                int val = p[i][j] - 1;
                dist += abs(i - val / 3) + abs(j - val % 3);
            }
    return dist;
}

pair<int,int> findZero(const vector<vector<int>>& p) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (p[i][j] == 0) return {i, j};
    return {0, 0};
}

vector<Node> getNext(const Node &cur) {
    vector<Node> res;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char mv[4] = {'U', 'D', 'L', 'R'};
 pair<int,int> zeroPos = findZero(cur.puzzle);
    int x = zeroPos.first, y = zeroPos.second;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            Node next = cur;
            swap(next.puzzle[x][y], next.puzzle[nx][ny]);
            next.h = heuristic(next.puzzle);
            next.path = cur.path + mv[k];
            res.push_back(next);
        }
    }
    return res;
}

void printPuzzle(const vector<vector<int>> &p) {
    for (auto &r : p) {
        for (int v : r) cout << v << " ";
        cout << "\n";
    }
}

void hillClimb(vector<vector<int>> start) {
    Node cur = {start, heuristic(start), ""};
    cout << "Initial heuristic: " << cur.h << endl;

    while (true) {
        if (isGoal(cur.puzzle)) {
            cout << "\nGoal reached!\n";
            cout << "Moves: " << cur.path.size() << "\n";
            cout << "Path: " << cur.path << "\n";
            return;
        }

        vector<Node> nextStates = getNext(cur);
        Node best = cur;
        for (auto &n : nextStates)
            if (n.h < best.h)
                best = n;

        if (best.h >= cur.h) {
            cout << "\nReached local minimum or plateau.\n";
            cout << "Final heuristic: " << cur.h << "\n";
            cout << "Path: " << cur.path << "\n";
            return;
        }

        cout << "Current h = " << cur.h
             << " -> Next h = " << best.h
             << " | Move: " << best.path.back() << endl;

        cur = best;
    }
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter puzzle (use 0 for blank):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];
    hillClimb(start);
}

