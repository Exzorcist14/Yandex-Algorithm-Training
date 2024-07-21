#include <bits/stdc++.h>
using namespace std;

void dfs(bool& possible, int vert1, int color, vector<vector<int>>& graph, vector<int>& colors) {
    colors[vert1] = color;

    for (auto& vert2 : graph[vert1]) {
        if (colors[vert2] == 0) {
            dfs(possible, vert2, 3 - color, graph, colors);
        } else if (colors[vert2] == color) {
            possible = false;
            break;
        }
    }
}


void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph(N + 1);

    int vert1, vert2;
    for (int i = 1; i <= N; ++i) {
        fin >> vert1 >> vert2;
        graph[vert1].push_back(vert2);
        graph[vert2].push_back(vert1);
    }

    vector<int> colors(N + 1);
    bool possible = true;
    int color = 1;

    for (int vert = 1; vert <= N && possible; ++vert) {
        if (colors[vert] == 0) {
            dfs(possible, vert, color, graph, colors);
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    solve();
    return 0;
}