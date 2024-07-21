#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, K, r, p;
    fin >> N >> K >> r >> p;

    int petyaPos = (r - 1) * 2 + p;

    int vasyaRow1 = (petyaPos + K) / 2 + (petyaPos + K) % 2;
    int vasyaRow2 = (petyaPos - K) / 2 + (petyaPos - K) % 2;

    if (petyaPos + K <= N && abs(vasyaRow1 - r) <= abs(r - vasyaRow2)) {
        cout << vasyaRow1 << "\n";
        cout << (2 - ((petyaPos + K) % 2 != 0)) << "\n";
    } else if (petyaPos - K >= 1) {
        cout << vasyaRow2 << "\n";
        cout << (2 - ((petyaPos - K) % 2 != 0)) << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    solve();
    return 0;
}
