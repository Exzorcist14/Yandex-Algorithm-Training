#include <bits/stdc++.h>
using namespace std;

void dfs(int vert1, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& comp) {
    visited[vert1] = true;
    comp.push_back(vert1);

    for (auto& vert2 : graph[vert1]) {
        if (!visited[vert2]) {
            dfs(vert2, graph, visited, comp);
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
    vector<int> comp;

    dfs(1, graph, visited, comp);

    sort(comp.begin(), comp.end());

    cout << comp.size() << "\n";
    for (auto& vert : comp) {
        cout << vert << " ";
    }
}

int main() {
    solve();
    return 0;
}