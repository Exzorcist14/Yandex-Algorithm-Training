#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int n, k;
    fin >> n >> k;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        fin >> seq[i];
    }

    vector<int> prefMin(n);

    int currMin;
    for (int i = 0; i < n; ++i) {
        if (i % k != 0) {
            currMin = min(seq[i], currMin);
        } else {
            currMin = seq[i];
        }

        prefMin[i] = currMin;
    }

    vector<int> postMin(n);

    currMin = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (i % k != 0) {
            currMin = min(seq[i], currMin);
        } else {
            currMin = seq[i];
        }

        postMin[i] = currMin;
    }

    vector<int> windowMin(n - k + 1);
    for (int i = 0; i < n - k + 1; ++i) {
        windowMin[i] = min(postMin[i], prefMin[i + k - 1]);
    }

    for (auto& elem : windowMin) {
        cout << elem << "\n";
    }
}

int main() {
    solve();
    return 0;
}