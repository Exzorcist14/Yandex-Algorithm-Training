#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int k1, int m, int k2, int p2, int n2) {
    if (n2 <= m && k2 >= n2) {
        int p1 = -1;
        int n1 = -1;
        bool uncertaintyP = false;
        bool uncertaintyN = false;

        int p;
        int n;
        int leftBorder1;
        int rightBorder1;

        int s = 1;
        int leftBorder2 = ((n2 - 1) * s) + (m * s * (p2 - 1) + 1);
        int rightBorder2 = (n2 * s) + (m * s * (p2 - 1));

        while (leftBorder2 <= k2 && !(uncertaintyP && uncertaintyN) && s <= 1000000) {
            if (k2 >= leftBorder2 && k2 <= rightBorder2) {
                p = k1 / (m * s) + (k1 % (m * s) != 0 ? 1 : 0);
                n = (k1 - m * s * (p - 1)) / s + ((k1 - m * s * (p - 1)) % s != 0 ? 1 : 0);

                if (p >= 1 && n >= 1 && n <= m) {
                    if (p != p1 && p1 != -1) {
                        p1 = 0;
                        uncertaintyP = true;
                    } else {
                        p1 = p;
                    }

                    if (n != n1 && n1 != -1) {
                        n1 = 0;
                        uncertaintyN = true;
                    } else {
                        n1 = n;
                    }
                }
            }

            s++;
            leftBorder2 = (n2 - 1) * s + m * s * (p2 - 1) + 1;
            rightBorder2 = n2 * s + m * s * (p2 - 1);

        }

        if (p1 != -1) {
            cout << p1 << " " << n1 << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    } else {
        cout << -1 << " " << -1 << "\n";
    }

}

int32_t main() {
    int k1, m, k2, p2, n2;
    cin >> k1;
    cin >> m;
    cin >> k2;
    cin >> p2;
    cin >> n2;

    solve(k1, m, k2, p2, n2);

    return 0;
}