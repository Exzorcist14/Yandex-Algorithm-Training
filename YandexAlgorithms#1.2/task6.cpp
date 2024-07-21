#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(vector<int> seq, int l) {
    for (int i = l; i < (seq.size() + l) / 2; i++) {
        if (seq[i] != seq[(seq.size() + l) - i - 1]) {
            return false;
        }
    }

    return true;
}

void solve(vector<int> seq) {
    vector<int> add;

    int l = 0;
    while (!isPalindrome(seq, l)) {
        add.push_back(seq[l]);
        l++;
    }

    cout << add.size() << "\n";

    for (int i = add.size() - 1; i >= 0; i--) {
        cout << add[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq(n);

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    solve(seq);

    return 0;
}