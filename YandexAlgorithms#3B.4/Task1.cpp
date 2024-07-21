#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> table;
    vector<int> str(M + 1);

    table.push_back(str);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            fin >> str[j];
        }

        table.push_back(str);
    }

    vector<vector<int>> dp;
    vector<int> temp(M + 1, 1000000);
    for (int i = 0; i <= N; ++i) {
        dp.push_back(temp);
    }
    dp[1][1] = table[1][1];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!(i == 1 && j == 1)) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + table[i][j];
            }
        }
    }

    cout << dp[N][M] << "\n";
}

int main() {
    solve();
    return 0;
}