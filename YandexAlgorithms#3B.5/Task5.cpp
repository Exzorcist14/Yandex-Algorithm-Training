#include <bits/stdc++.h>
using namespace std;

void dfs(int& endCycle, int vert1, int prev, vector<vector<int>>& graph, vector<int>& cond, vector<int>& source) {
    ++cond[vert1];

    for (int vert2 = 1; vert2 <= graph.size(); ++vert2) {

        if (!endCycle && graph[vert1][vert2] == 1 && vert2 != prev) {

            if (cond[vert2] == 0) {
                source[vert2] = vert1;
                dfs(endCycle, vert2, vert1, graph, cond, source);
            } else if (cond[vert2] == 1) {
                source[vert2] = vert1;
                endCycle = vert2;
                break;
            }
        }
    }

    ++cond[vert1];
}

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            fin >> graph[i][j];
        }
    }

    vector<int> cond(N + 1);
    vector<int> source(N + 1);
    int endCycle = 0;

    for (int vert = 1; vert <= N && !endCycle; ++vert) {
        if (cond[vert] == 0) {
            dfs(endCycle, vert, vert, graph, cond, source);
        }
    }



    if (endCycle != 0) {
        cout << "YES" << "\n";

        vector<int> cycle;
        int vert = source[endCycle];

        while (vert != endCycle) {
            cycle.push_back(vert);
            vert = source[vert];
        }

        cycle.push_back(endCycle);

        cout << cycle.size() << "\n";
        for (int i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] << " ";
        }
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    solve();
    return 0;
}