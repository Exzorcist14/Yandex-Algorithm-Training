#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(int K, const vector<pair<int, int>>& XY) {
    int minX = XY[0].first;
    int minY = XY[0].second;
    int maxX = XY[0].first;
    int maxY = XY[0].second;

    for (auto& elem : XY) {
        if (minX > elem.first) {
            minX = elem.first;
        } else if (maxX < elem.first) {
            maxX = elem.first;
        }

        if (minY > elem.second) {
            minY = elem.second;
        } else if (maxY < elem.second) {
            maxY = elem.second;
        }
    }

    cout << minX << " " << minY << " " << maxX << " " << maxY << "\n";
}

int32_t main() {
    int K;
    cin >> K;

    vector<pair<int, int>> XY(K);

    for (int i = 0; i < K; i++) {
        cin >> XY[i].first >> XY[i].second;
    }

    solve(K, XY);

    return 0;
}
