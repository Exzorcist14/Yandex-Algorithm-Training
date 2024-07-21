#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int n, int k, int d) {

    if ((k - (n * 10) % k) % k <= 9) {
        cout << n << (k - (n * 10) % k) % k;

        for (int _ = 1; _ < d; _++) {
            cout << 0;
        }
    } else {
        cout << -1 << "\n";
    }
}

int32_t main() {
    int n, k, d;

    cin >> n >> k >> d;

    solve(n, k, d);

    return 0;
}