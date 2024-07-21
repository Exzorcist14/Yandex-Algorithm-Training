#include <bits/stdc++.h>
using namespace std;

void dfs(int vert1, int currComp, vector<vector<int>>& graph, vector<bool>& visited, unordered_map<int, vector<int>>& comp) {
    visited[vert1] = true;
    comp[currComp].push_back(vert1);

    for (auto& vert2 : graph[vert1]) {
        if (!visited[vert2]) {
            dfs(vert2, currComp, graph, visited, comp);
        }
    }
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
        graph[vert2].push_back(vert1);
    }

    vector<bool> visited(N + 1);
    unordered_map<int, vector<int>> comp;
    int currComp = 1;

    for (int vert = 1; vert <= N; ++vert) {
        if (!visited[vert]) {
            dfs(vert, currComp, graph, visited, comp);
            ++currComp;
        }
    }

    cout << comp.size() << "\n";
    for (auto [c, verts] : comp) {
        sort(verts.begin(), verts.end());

        cout << verts.size() << "\n";
        for (auto& v : verts) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}