#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) {
        fin >> A[i] >> B[i] >> C[i];
    }

    vector<int> t(N);
    t[0] = A[0];
    t[1] = min(t[0] + A[1], B[0]);
    t[2] = min(min(t[1] + A[2], t[0] + B[1]), C[0]);

    for (int i = 3; i < N; i++) {
        t[i] = min(min(t[i - 3] + C[i - 2], t[i - 2] + B[i - 1]), t[i - 1] + A[i]);
    }

    cout << t.back() << "\n";
}

int main() {
    solve();
    return 0;
}