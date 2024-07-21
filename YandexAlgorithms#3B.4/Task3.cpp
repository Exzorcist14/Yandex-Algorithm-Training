#include <bits/stdc++.h>
using namespace std;

bool inside(int i, int j, int N, int M) {
    return (i >= 0 && i < N && j >= 0 && j < M);
}

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> dp(N, vector<int>(M));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (inside(i - 2, j - 1, N, M)) {
                dp[i][j] += dp[i - 2][j - 1];
            }

            if (inside(i - 1, j - 2, N, M)) {
                dp[i][j] += dp[i - 1][j - 2];
            }
        }
    }

    cout << dp[N - 1][M - 1] << "\n";
}

int main() {
    solve();
    return 0;
}
