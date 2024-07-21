#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int N, int K, const vector<int>& prices) {
    int maxDiff = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < (i + K + 1) && j < N; j++) {
            maxDiff = max(maxDiff, prices[j] - prices[i]);
        }
    }

    cout << maxDiff << "\n";
}

int32_t main() {
    int N, K;
    cin >> N >> K;

    vector<int> prices(N);

    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    solve(N, K, prices);

    return 0;
}
