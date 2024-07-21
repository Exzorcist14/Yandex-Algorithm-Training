#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j * j * j <= i; ++j) {
            dp[i] = min(dp[i - j * j * j] + 1, dp[i]);
        }
    }

    cout << dp[N] << "\n";
}

int main() {
    solve();
    return 0;
}