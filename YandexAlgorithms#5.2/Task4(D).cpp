#include <bits/stdc++.h>

using namespace std;

int countNumberOfAdjacent(int x, int y, const vector<vector<bool>>& field) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int number = 0;

    for (int k = 0; k < dx.size(); k++) {
        if (field[x + dx[k]][y + dy[k]]) {
            ++number;
        }
    }

    return number;
}

void solve(int N, const vector<pair<int, int>>& cells) {
    vector<vector<bool>> field(10, {false, false, false, false, false, false, false, false, false, false});
    int p = 0;

    for (auto& elem : cells) {
        field[elem.first][elem.second] = true;

        p += 4 - 2 * countNumberOfAdjacent(elem.first, elem.second, field);
    }

    cout << p << "\n";
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cells(N);
    for (int i = 0; i < N; i++) {
        cin >> cells[i].first >> cells[i].second;
    }

    solve(N, cells);

    return 0;
}
