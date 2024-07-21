#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(const map<int, int>& repetitionsOfNumbers, int n) {
    int maxRepetitions = 0;
    for (auto& elem : repetitionsOfNumbers) {
        maxRepetitions = max(elem.second, maxRepetitions);
    }

    int minCount;

    if (repetitionsOfNumbers.size() == 1) {
        minCount = 0;
    } else {
        minCount = n - maxRepetitions;
    }

    pair<int, int> prev = {-1, -1};
    for (auto& elem : repetitionsOfNumbers) {
        if (elem.first - prev.first == 1) {
            minCount = min(n - (elem.second + prev.second), minCount);
        }

        prev = elem;
    }

    cout << minCount << "\n";
}

int32_t main() {
    int n;
    cin >> n;

    map<int, int> repetitionsOfNumbers;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        repetitionsOfNumbers[temp]++;
    }

    solve(repetitionsOfNumbers, n);

    return 0;
}
