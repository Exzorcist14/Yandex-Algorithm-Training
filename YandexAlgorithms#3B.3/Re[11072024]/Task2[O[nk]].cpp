#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, k;
    fin >> N >> k;

    vector<int> dp(N + 1);
    dp[1] = 1;

    for (int i = 2; i < N + 1; ++i) {
        for (int jump = 1; jump <= k; ++jump) {
            if (i - jump >= 1) {
                dp[i] += dp[i - jump];
            }
        }
    }

    cout << dp[N] << "\n";
}

int main() {
    solve();
    return 0;
}