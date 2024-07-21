#include <bits/stdc++.h>
using namespace std;

const vector<int> dx = {-1, -2, -2, -1, 1, 2,  2,  1};
const vector<int> dy = {-2, -1,  1,  2, 2, 1, -1, -2};

pair<int, int> readPlace(ifstream& fin) {
    string place;
    fin >> place;

    return {place[0] - 97, place[1] - 49};
}

bool onBoard(const int& i, const int& j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void solve() {
    ifstream fin("input.txt");

    auto [i1, j1] = readPlace(fin);
    auto [i2, j2] = readPlace(fin);

    vector<vector<int>> redDist(8, vector<int>(8, -1));
    redDist[i1][j1] = 0;

    vector<vector<int>> greenDist(8, vector<int>(8, -1));
    greenDist[i2][j2] = 0;

    queue<pair<int, int>> q;
    q.emplace(i1, j1);

    int i, j, newI, newJ;

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int sh = 0; sh < 8; ++sh) {
            newI = i + dx[sh];
            newJ = j + dy[sh];

            if (onBoard(newI, newJ) && redDist[newI][newJ] == -1) {

                redDist[newI][newJ] = redDist[i][j] + 1;
                q.emplace(newI, newJ);
            }
        }
    }

    q.emplace(i2, j2);

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int sh = 0; sh < 8; ++sh) {
            newI = i + dx[sh];
            newJ = j + dy[sh];

            if (onBoard(newI, newJ) && greenDist[newI][newJ] == -1) {
                greenDist[newI][newJ] = greenDist[i][j] + 1;

                q.emplace(newI, newJ);
            }
        }
    }

    int ans = INT_MAX;

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {

            if (redDist[i][j] == greenDist[i][j]) {
                ans = min(ans, redDist[i][j]);
            }
        }
    }

    if (ans != INT_MAX) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }

}

int main() {
    solve();
    return 0;
}