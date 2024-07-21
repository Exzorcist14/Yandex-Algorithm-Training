#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");
    int N;
    fin >> N;

    vector<int> seq(N + 1);
    seq[1] = 2;
    seq[2] = 4;
    seq[3] = 7;

    for (int i = 4; i <= N; ++i) {
        seq[i] = seq[i - 1] + seq[i - 2] + seq[i - 3];
    }

    cout << seq[N] << "\n";
}

int main() {
    solve();
    return 0;
}