#include <bits/stdc++.h>

#define int long long

using namespace std;

int arithmeticSum(int& s) {
    return (1 + s) * s / 2;
}

int leftBinarySearch(int& n) {

    int l = 1;
    int r = 2000000000;
    int mid;

    while (l != r) {
        mid = (l + r) / 2;

        if (arithmeticSum(mid) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;

    int s = leftBinarySearch(n);
    int shift = arithmeticSum(s) - n;
    int numerator, denominator;

    if (s % 2 == 0) {
        numerator = 1 + shift;
        denominator = s - shift;
    } else {
        numerator = s - shift;
        denominator = 1 + shift;
    }

    cout << numerator << "/" << denominator << "\n";
}

int32_t main() {
    solve();
    return 0;
}
