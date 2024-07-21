#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(vector<int> coords) {
    unordered_set<int> verticals;

    for (int i = 0; i < coords.size(); i += 2) {
        verticals.insert(coords[i]);
    }

    cout << verticals.size() << "\n";
}

int32_t main() {
    int n;
    cin >> n;

    vector<int> coords(n*2);
    for (int i = 0; i < n*2; i++) {
        cin >> coords[i];
    }

    solve(coords);

    return 0;
}