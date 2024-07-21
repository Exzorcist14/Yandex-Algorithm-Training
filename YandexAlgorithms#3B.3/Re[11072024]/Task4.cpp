#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> A(N + 1);
    vector<int> B(N + 1);
    vector<int> C(N + 1);

    for (int i = 1; i < N + 1; ++i) {
        fin >> A[i] >> B[i] >> C[i];
    }

    vector<int> dp(N + 1, 0);

    for (int i = 1; i < N + 1; ++i) {
        dp[i] = dp[i - 1] + A[i];

        if (i - 2 >= 0) {
            dp[i] = min(dp[i - 2] + B[i - 1], dp[i]);
        }

        if (i - 3 >= 0) {
            dp[i] = min(dp[i - 3] + C[i - 2], dp[i]);
        }
    }

    cout << dp[N] << "\n";
}

int main() {
    solve();
    return 0;
}