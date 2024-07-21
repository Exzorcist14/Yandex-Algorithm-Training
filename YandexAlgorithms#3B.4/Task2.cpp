#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> table(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            fin >> table[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));
    dp[1][1] = table[1][1];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i != 1 || j != 1) {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + table[i][j];
                } else {
                    dp[i][j] = dp[i][j - 1] + table[i][j];
                }
            }
        }
    }

    int ans = dp[N][M];
    stack<char> path;

    int i = N;
    int j = M;

    while (!(i == 1 && j == 1)) {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            i = i - 1;
            path.push('D');
        } else {
            j = j - 1;
            path.push('R');
        }
    }

    cout << ans << "\n";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}

int main() {
    solve();
    return 0;
}