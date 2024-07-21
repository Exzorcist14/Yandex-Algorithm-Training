#include <bits/stdc++.h>

#define int long long

using namespace std;

int turnLeft(int n, const vector<int>& sectors, int a, int b, int k) {
    int shiftA = (a - 1) / k;
    int leftBorder = (shiftA % n);

    int currMax = leftBorder;

    int shiftB = (b - 1) / k;
    int rightBorder = (shiftB % n);

    if (shiftB - shiftA >= n) {
        for (int i = 0; i < n; i++) {
            currMax = max(sectors[i], currMax);
        }
    } else if (leftBorder <= rightBorder) {
        for (int i = leftBorder; i <= rightBorder; i++) {
            currMax = max(sectors[i], currMax);
        }
    } else {
        for (int i = leftBorder; i <= (rightBorder + n); i++) {
            currMax = max(sectors[i % n], currMax);
        }
    }

    return currMax;
}

int turnRight(int n, const vector<int>& sectors, int a, int b, int k) {
    int shiftA = (a - 1) / k;
    int leftBorder = (n - shiftA % n) % n;

    int currMax = leftBorder;

    int shiftB = (b - 1) / k;
    int rightBorder = (n - shiftB % n) % n;

    if (shiftB - shiftA >= n) {
        for (int i = 0; i < n; i++) {
            currMax = max(sectors[i], currMax);
        }
    } else if (leftBorder >= rightBorder) {
        for (int i = leftBorder; i >= rightBorder; i--) {
            currMax = max(sectors[i], currMax);
        }
    } else {
        for (int i = leftBorder + n; i >= rightBorder; i--) {
            currMax = max(sectors[i % n], currMax);
        }
    }

    return currMax;
}

void solve(int n, const vector<int>& sectors, int a, int b, int k) {
    int ans = turnLeft(n, sectors, a, b, k);
    ans = max(ans, turnRight(n, sectors, a, b, k));

    cout << ans << "\n";
}

int32_t main() {
    int n;
    cin >> n;

    vector<int> sectors(n);
    for (int i = 0; i < n; i++) {
        cin >> sectors[i];
    }

    int a, b, k;
    cin >> a >> b >> k;

    solve(n, sectors, a, b, k);

    return 0;
}
