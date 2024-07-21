#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> dp(N + 1, INT_MAX);
    vector<int> prev(N + 1, -1);
    dp[1] = 0;

    for (int i = 2; i < N + 1; ++i) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0 and dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }

        if (i % 3 == 0 and dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    cout << dp[N] << "\n";

    vector<int> ans;
    int number = N;

    while (number != -1) {
        ans.push_back(number);
        number = prev[number];
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
}

int main() {
    solve();
    return 0;
}