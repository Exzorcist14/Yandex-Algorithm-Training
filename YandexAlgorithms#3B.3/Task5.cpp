#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> nail(N);
    for (int i = 0; i < N; ++i) {
        fin >> nail[i];
    }

    sort(nail.begin(), nail.end());

    vector<int> diff;
    for (int i = 1; i < N; ++i) {
        diff.push_back(nail[i] - nail[i - 1]);
    }

    vector<int> dp(N - 1);
    dp[0] = diff[0];
    for (int i = 1; i < N - 1; ++i) {
        if (i == 1) {
            dp[i] = dp[i - 1] + diff[i];
        } else {
            dp[i] = min(dp[i - 1], dp[i - 2]) + diff[i];
        }
    }

    cout << dp.back() << "\n";
}

int main() {
    solve();
    return 0;
}
