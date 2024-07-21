#include <bits/stdc++.h>

#define int long long

using namespace std;

double findDistance(int x, int L) {
    x %= L;

    if (x <= double(L / 2)) {
        return x;
    } else {
        return L - x;
    }
}

void solve(double L, double x1, double v1, double x2, double v2) {
    double t = 1000000001;

    if (findDistance(x1, L) == findDistance(x2, L)) {
        t = 0;
    } else if (x1 != x2 && !(v1 == 0 && v2 == 0)) {
        for (int k = -10000000; k <= 10000000; k++) {
            double exp1 = (x1 - x2 - L * k) / (-(v1 - v2)); // sin((a - b) / 2) == 0
            if (exp1 >= 0) {
                t = min(t, exp1);
            }

            double exp2 = (x1 + x2 - L * k) / (-(v1 + v2)); // sin((a + b) / 2) == 0
            if (exp2 >= 0) {
                t = min(t, exp2);
            }
        }
    } else {
        t = -1;
    }

    if (t != -1) {
        cout << "Yes" << "\n" << setprecision(10) << t << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int32_t main() {
    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;

    solve(L, x1, v1, x2, v2);

    return 0;
}