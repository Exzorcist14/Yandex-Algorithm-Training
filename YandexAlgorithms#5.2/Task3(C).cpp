#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int N, vector<int> l) {
    int ans;

    int maxL = l[0];
    int sumL = 0;

    for (int i = 0; i < N; i++) {
        maxL = max(maxL, l[i]);

        sumL += l[i];
    }

    if (sumL - maxL < maxL) {
        ans = maxL - (sumL - maxL);
    } else {
        ans = sumL;
    }

    cout << ans << "\n";
}

int32_t main() {
    int N;
    cin >> N;

    vector<int> l(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    solve(N, l);

    return 0;
}