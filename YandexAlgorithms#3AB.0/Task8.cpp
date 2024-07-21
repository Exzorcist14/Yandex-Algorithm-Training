#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int K;
    fin >> K;

    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;

    int x, y;
    while (K --> 0) {
        fin >> x >> y;

        minX = min(x, minX);
        minY = min(y, minY);
        maxX = max(x, maxX);
        maxY = max(y, maxY);
    }

    cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY << "\n";
}

int main() {
    solve();
    return 0;
}