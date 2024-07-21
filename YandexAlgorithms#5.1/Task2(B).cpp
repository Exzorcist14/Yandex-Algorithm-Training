#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int A1, int B1, int A2, int B2, int situation) {
    int ans = 0;

    if (A1 + A2 <= B1 + B2) {
        if (situation == 1) {
            ans = (A2 + B1 + B2 - (A1 + A2)) > B1 ?
                  (B1 + B2 - (A1 + A2)) :
                  (B1 + B2 - (A1 + A2)) + 1;
        } else {
            ans = (A1 > B2) ?
                  (B1 + B2 - (A1 + A2)) :
                  (B1 + B2 - (A1 + A2)) + 1;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    int A1, B1;
    int A2, B2;
    int situation;
    char _;

    cin >> A1 >> _ >> B1 >> A2 >> _ >> B2 >> situation;

    solve(A1, B1, A2, B2, situation);

    return 0;
}