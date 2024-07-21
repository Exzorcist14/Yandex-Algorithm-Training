#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;

    vector<int> cities(n, -1);
    stack<pair<int, int>> tribesOfTheEast;
    int city;

    for (int i = 0; i < n; i++) {
        fin >> city;

        while (!tribesOfTheEast.empty() && city < tribesOfTheEast.top().first) {
            cities[tribesOfTheEast.top().second] = i;
            tribesOfTheEast.pop();
        }

        tribesOfTheEast.push({city, i});
    }

    for (auto& elem : cities) {
        cout << elem << " ";
    }
    cout << "\n";
}

int32_t main() {
    solve();
    return 0;
}
