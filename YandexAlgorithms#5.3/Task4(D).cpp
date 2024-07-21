#include <bits/stdc++.h>

#define int long long

using namespace std;

void input(int& n, int& k, unordered_map<int, vector<int>>& seq) {
    cin >> n >> k;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        seq[temp].push_back(i);
    }
}

void solve() {
    int n, k;
    unordered_map<int, vector<int>> seq;
    input(n, k, seq);

    bool flag = false;

    for (auto& elem : seq) {
        for (int i = 0; i < elem.second.size() - 1; i++) {
            if (elem.second[i+1] - elem.second[i] <= k) {
                flag = true;
                break;
            }
        }

        if (flag) {
            break;
        }
    }

    if (flag) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int32_t main() {
    solve();

    return 0;
}
