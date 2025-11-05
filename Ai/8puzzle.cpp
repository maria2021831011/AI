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
                dist += abs(i - val/3) + abs(j - val%3);
            }
    return dist;
}

pair<int,int> findZero(const vector<vector<int>>& p) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (p[i][j] == 0) return {i,j};
    return {0,0};
}

vector<Node> getNext(const Node &cur) {
    vector<Node> res;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char moves[4] = {'U','D','L','R'};
    pair<int,int> zeroPos = findZero(cur.puzzle);
    int x = zeroPos.first, y = zeroPos.second;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx>=0 && nx<3 && ny>=0 && ny<3) {
            Node next = cur;
            swap(next.puzzle[x][y], next.puzzle[nx][ny]);
            next.h = heuristic(next.puzzle);
            next.path = cur.path + moves[k];
            res.push_back(next);
        }
    }
    return res;
}

void hillClimb(vector<vector<int>> start) {
    Node cur = {start, heuristic(start), ""};
    while (true) {
        if (isGoal(cur.puzzle)) {
            cout << "Goal reached!\n";
            cout << "Path: " << cur.path << "\n";
            cout << "Moves: " << cur.path.size() << endl;
            return;
        }
        vector<Node> nextStates = getNext(cur);
        Node best = cur;
        for (auto &n : nextStates)
            if (n.h < best.h) best = n;
        if (best.h >= cur.h) {
            cout << "Reached local minimum or plateau.\n";
            cout << "Heuristic: " << cur.h << "\n";
            cout << "Path: " << cur.path << endl;
            return;
        }
        cur = best;
    }
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];
    hillClimb(start);
}

/*#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> puzzle;
    int g, h;
    string path;
    bool operator>(const Node &other) const {
        return g + h > other.g + other.h;
    }
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
                dist += abs(i - val/3) + abs(j - val%3);
            }
    return dist;
}

pair<int,int> findZero(const vector<vector<int>>& p) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (p[i][j] == 0) return {i,j};
    return {0,0};
}

vector<Node> getNext(const Node &cur) {
    vector<Node> res;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char moves[4] = {'U','D','L','R'};
    pair<int,int> zeroPos = findZero(cur.puzzle);
    int x = zeroPos.first, y = zeroPos.second;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx>=0 && nx<3 && ny>=0 && ny<3) {
            Node next = cur;
            swap(next.puzzle[x][y], next.puzzle[nx][ny]);
            next.g = cur.g + 1;
            next.h = heuristic(next.puzzle);
            next.path = cur.path + moves[k];
            res.push_back(next);
        }
    }
    return res;
}

void solve(vector<vector<int>> start) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> visited;
    Node sn = {start, 0, heuristic(start), ""};
    pq.push(sn);
    while(!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (isGoal(cur.puzzle)) {
            cout << "Goal reached!\n";
            cout << "Moves: " << cur.g << "\n";
            cout << "Path: " << cur.path << endl;
            return;
        }
        if (visited.count(cur.puzzle)) continue;
        visited.insert(cur.puzzle);
        for (auto next : getNext(cur)) {
            if (!visited.count(next.puzzle)) pq.push(next);
        }
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];
    solve(start);
}
/*#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> puzzle;
    int g, h;
    string path;
    bool operator>(const Node &other) const {
        return g + h > other.g + other.h;
    }
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
                dist += abs(i - val/3) + abs(j - val%3);
            }
    return dist;
}

pair<int,int> findZero(const vector<vector<int>>& p) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (p[i][j] == 0) return {i,j};
    return {0,0};
}

vector<Node> getNext(const Node &cur) {
    vector<Node> res;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char moves[4] = {'U','D','L','R'};
    pair<int,int> zeroPos = findZero(cur.puzzle);
    int x = zeroPos.first, y = zeroPos.second;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx>=0 && nx<3 && ny>=0 && ny<3) {
            Node next = cur;
            swap(next.puzzle[x][y], next.puzzle[nx][ny]);
            next.g = cur.g + 1;
            next.h = heuristic(next.puzzle);
            next.path = cur.path + moves[k];
            res.push_back(next);
        }
    }
    return res;
}

void solve(vector<vector<int>> start) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> visited;
    Node sn = {start, 0, heuristic(start), ""};
    pq.push(sn);
    while(!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (isGoal(cur.puzzle)) {
            cout << "Goal reached!\n";
            cout << "Moves: " << cur.g << "\n";
            cout << "Path: " << cur.path << endl;
            return;
        }
        if (visited.count(cur.puzzle)) continue;
        visited.insert(cur.puzzle);
        for (auto next : getNext(cur)) {
            if (!visited.count(next.puzzle)) pq.push(next);
        }
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];
    solve(start);
}
*/
