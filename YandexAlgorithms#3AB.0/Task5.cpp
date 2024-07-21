#include <bits/stdc++.h>
#define int long long
using namespace std;

void findMinimumIndex(vector<int>& c, int& start, int& end, vector<int>& minInd) {
    minInd.clear();

    int minC = 1000000001;
    for (int i = start; i <= end; ++i) {
        minC = min(minC, c[i]);
    }

    for (int i = start; i <= end; ++i) {
        if (c[i] == minC) {
            minInd.push_back(i);
        }
    }
}

void divide(queue<pair<int, int>>& seg, int start, int end, vector<int>& minInd) {
    if ((minInd.front() - 1) - start > 0) {
        seg.emplace(start, minInd.front() - 1);
    }

    for (int j = 0; j < minInd.size() - 1; ++j) {
        if ((minInd[j + 1] - 1) - (minInd[j] + 1) > 0) {
            seg.emplace(minInd[j] + 1, minInd[j + 1] - 1);
        }
    }

    if ((end - (minInd.back() + 1) > 0)) {
        seg.emplace(minInd.back() + 1, end);
    }
}

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
        fin >> c[i];
    }

    queue<pair<int, int>> seg;
    seg.emplace(0, N - 1);

    vector<int> minInd;
    int minC;

    int ans = 0;

    while (!seg.empty()) {
        auto& [start, end] = seg.front();
        seg.pop();

        findMinimumIndex(c, start, end, minInd);
        minC = c[minInd.front()];

        ans += minC * (end - start);
        for (int i = start; i <= end; ++i) {
            c[i] -= minC;
        }

        divide(seg, start, end, minInd);
    }

    cout << ans << "\n";
}

int32_t main() {
    solve();
    return 0;
}