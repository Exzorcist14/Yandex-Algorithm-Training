#include <bits/stdc++.h>

#define int long long

using namespace std;

bool isNotLess(int x, int& leftBorder) {
    return (x >= leftBorder);
}
bool isNotBigger(int x, int& rightBorder) {
    return (x <= rightBorder);
}

int leftBinSearch(int& leftBorder, vector<int>& seq) {

    int l = 0;
    int r = seq.size() - 1;
    int mid;

    while (l < r) {
        mid = (l + r) / 2;

        if (isNotLess(seq[mid], leftBorder)) {
            r = mid;
        } else {
            l = mid + 1;
        }

    }

    return isNotLess(seq[l], leftBorder) ? l : -1;
}

int rightBinSearch(int& rightBorder, vector<int>& seq) {

    int l = 0;
    int r = seq.size() - 1;
    int mid;

    while (l < r) {

        mid = (l + r + 1) / 2;

        if (isNotBigger(seq[mid], rightBorder)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return (isNotBigger(seq[r], rightBorder) ? r : -1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int k;
    cin >> k;
    vector<pair<int, int>> borders(k);
    for (int i = 0; i < k; i++) {
        cin >> borders[i].first >> borders[i].second;
    }

    sort(seq.begin(), seq.end());

    vector<int> ans;
    int left;
    int right;
    for (auto& pair : borders) {
        left = leftBinSearch(pair.first, seq);
        right = rightBinSearch(pair.second, seq);

        if (left == -1 || right == -1) {
            ans.push_back(0);
        } else {
            ans.push_back(right - left + 1);
        }
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    solve();

    return 0;
}
