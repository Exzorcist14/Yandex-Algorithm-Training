#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j * j] + 1);
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    solve();
    return 0;
}
