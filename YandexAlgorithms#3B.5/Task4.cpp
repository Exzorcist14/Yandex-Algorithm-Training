#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& ans, bool& endCycle, int vert1, vector<vector<int>>& graph, vector<int>& cond) {
    ++cond[vert1];

    for (auto& vert2 : graph[vert1]) {
        if (!endCycle) {
            if (cond[vert2] == 0) {
                dfs(ans, endCycle, vert2, graph, cond);
            } else if (cond[vert2] == 1) {
                endCycle = true;
                break;
            }
        }
    }

    ans.push_back(vert1);
    ++cond[vert1];
}

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph(N + 1);

    int vert1, vert2;
    for (int i = 0; i < M; ++i) {
        fin >> vert1 >> vert2;
        graph[vert1].push_back(vert2);
    }

    vector<int> ans;

    vector<int> cond(N + 1);
    bool endCycle = false;
    for (int vert = 1; vert <= N && !endCycle; ++vert) {
        if (cond[vert] == 0) {
            dfs(ans, endCycle, vert, graph, cond);
        }
    }

    if (!endCycle) {
        for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
            cout << (*it) << " ";
        }
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    solve();
    return 0;
}