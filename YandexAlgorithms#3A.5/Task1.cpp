#include <bits/stdc++.h>
using namespace std;

const vector<int> dx = {-1, 0,  0, 1};
const vector<int> dy = { 0, 1, -1, 0};

void dfs(int i, int j, vector<vector<bool>>& visited, int& ans, vector<vector<int>>& maze) {
    ++ans;

    visited[i][j] = true;

    for (int sh = 0; sh < 4; ++sh) {

        int newI = i + dx[sh];
        int newJ = j + dy[sh];

        if (!visited[newI][newJ] && maze[newI][newJ] != -1) {
            dfs(newI, newJ, visited, ans, maze);
        }
    }
}

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<vector<int>> maze(N, vector<int>(N));
    char cell;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> cell;

            if (cell == '.') {
                maze[i][j] = 1;
            } else {
                maze[i][j] = -1;
            }
        }
    }

    int i, j;
    fin >> i >> j;

    int ans = 0;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    dfs(i - 1, j - 1, visited, ans, maze);

    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}