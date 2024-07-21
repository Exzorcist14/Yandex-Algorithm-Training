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

    multiset<int> window;

    for (int i = 0; i < min(n, k); ++i) {
        window.insert(seq[i]);
    }

    cout << (*window.begin()) << "\n";

    for (int i = k; i < n; ++i) {
       window.insert(seq[i]);

       if (window.find(seq[i - k]) != window.end()) {
           window.erase(window.find(seq[i - k]));
       }

       cout << (*window.begin()) << "\n";
    }
}

int main() {
    solve();
    return 0;
}