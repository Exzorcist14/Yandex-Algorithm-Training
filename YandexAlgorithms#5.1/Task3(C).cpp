#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(vector<int> a) {
    int ans = 0;

    for (int i = 0; i < a.size(); i++) {
        ans += a[i] / 4;

        if (a[i] % 4 >= 2) {
            ans += 2;
        } else if (a[i] % 4 == 1) {
            ans += 1;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(a);

    return 0;
}