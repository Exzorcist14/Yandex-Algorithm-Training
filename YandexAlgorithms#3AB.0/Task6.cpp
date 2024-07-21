#include <bits/stdc++.h>
using namespace std;

bool intersect(const pair<int, int>& a, const pair<int, int>& b) {
    return b.first <= a.second && b.second >= a.first;
}

void solve() {
    ifstream fin("input.txt");

    int M, N;
    fin >> M >> N;

    vector<pair<int, int>> part(N);
    vector<int> exists(N, 1);

    for (int i = 0; i < N; ++i) {
        fin >> part[i].first >> part[i].second;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (intersect(part[i], part[j])) {
                exists[j] = 0;
            }
        }
    }

    int ans = 0;
    for (bool elem : exists) {
        ans += elem;
    }

    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}