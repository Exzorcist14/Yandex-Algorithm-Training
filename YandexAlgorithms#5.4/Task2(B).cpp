#include <bits/stdc++.h>

#define int long long

using namespace std;

bool isTherePlace(const int& area, int k, const int& n) {
    k++;
    int empty = (1 + k) * k / 2 - 1;
    return (area <= n - empty);
}

void solve() {
    int n;
    cin >> n;

    vector<int> area = {1, 4};
    int lastK = -1;

    for (int i = 0; i < area.size(); i++) {
        if (isTherePlace(area[i], i, n)) {
            lastK = i;
        }
    }

    if (lastK != -1) {
        int diffBetweenDiffs = 3;
        int prevDiff = 3;
        int currDiff;
        int currS;

        for (int i = 2; i < n; i++) {
            currDiff = prevDiff + diffBetweenDiffs;
            currS = area[i - 1] + currDiff;

            diffBetweenDiffs++;
            prevDiff = currDiff;

            if (isTherePlace(currS, i, n)) {
                area.push_back(currS);
                lastK = i;
            } else {
                break;
            }
        }
    }

    cout << lastK + 1 << "\n";
}

int32_t main() {
    solve();

    return 0;
}
