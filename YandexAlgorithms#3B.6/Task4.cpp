#include <bits/stdc++.h>
using namespace std;

bool onCave(int i, int k, int j, int N) {
    return i >= 0 && k >= 0 && j >= 0 && i < N && j < N && k < N;
}

const vector<int> dx = { 0, 0,  0, 0, 1, -1};
const vector<int> dy = {-1, 0,  0, 1, 0,  0};
const vector<int> dz = { 0, 1, -1, 0, 0,  0};

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<vector<vector<int>>> cave(N, vector<vector<int>>(N, vector<int>(N)));
    int startI, startJ, startK;

    char buff;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                fin >> buff;

                if (buff == 'S') {
                    startI = i;
                    startJ = j;
                    startK = k;

                    cave[i][j][k] = 0;
                } else if (buff == '.') {
                    cave[i][j][k] = 0;
                } else {
                    cave[i][j][k] = -1;
                }
            }
        }
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(N, -1)));
    dist[startI][startJ][startK] = 0;

    queue<vector<int>> q;
    q.push({startI, startJ, startK});

    int i, j, k;
    while (!q.empty()) {
        i = q.front()[0];
        j = q.front()[1];
        k = q.front()[2];
        q.pop();

        for (int sh = 0; sh < 6; ++sh) {

            int newI = i + dx[sh];
            int newJ = j + dy[sh];
            int newK = k + dz[sh];

            if (onCave(newI, newJ, newK, N) && cave[newI][newJ][newK] != -1 &&
                    dist[newI][newJ][newK] == -1) {

                dist[newI][newJ][newK] = dist[i][j][k] + 1;

                if (newI == 0) {
                    cout << dist[newI][newJ][newK] << "\n";
                    return;
                }

                q.push({newI, newJ, newK});
            }
        }
    }
}

int main() {
    solve();
    return 0;
}