#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> statements) {
    unordered_set<int> beginnigs;

    for (int i = 0; i < statements.size(); i += 2) {
        if ((statements[i] + statements[i+1]) == (statements.size() / 2 - 1) && (statements[i] >= 0) && (statements[i+1] >= 0)) {
            beginnigs.insert(statements[i]);
        }
    }

    cout << beginnigs.size() << "\n";
}

int main() {
    int n;
    cin >> n;

    vector<int> statements(n*2);
    for (int i = 0; i < n*2; i++) {
        cin >> statements[i];
    }

    solve(statements);

    return 0;
}