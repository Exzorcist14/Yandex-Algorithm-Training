#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;

    vector<long long> dp(n + 1);
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;

    for (int i = 4; i < n + 1; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n] << "\n";
}

int main() {
    solve();
    return 0;
}