#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int P, int V, int Q, int M) {
    int ans;

    int left;
    int right;

    if ((max(P, Q) - min(P, Q)) > (V + M)) {
        ans = 2 * V + 2 * M + (P != Q ? 2 : 1);
    } else {
        left = min(P - V, Q - M);
        right = max(P + V, Q + M);

        ans = right - left + 1;
    }

    cout << ans << "\n";
}

int32_t main() {
    int P, V, Q, M;

    cin >> P >> V >> Q >> M;

    solve(P, V, Q, M);

    return 0;
}
