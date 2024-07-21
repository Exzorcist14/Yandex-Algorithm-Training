#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        fin >> A[i];
    }

    int M;
    fin >> M;

    vector<int> B(M + 1);
    for (int i = 1; i <= M; ++i) {
        fin >> B[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {

            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> subseq;

    int i = N;
    int j = M;

    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            subseq.push_back(A[i]);
            i = i - 1;
            j = j - 1;
        } else {
            if (i - 1 >= 1 && dp[i - 1][j] > dp[i][j - 1] || j - 1 == 0) {
                i = i - 1;
            } else {
                j = j - 1;
            }
        }
    }

    for (auto it = subseq.rbegin(); it != subseq.rend(); ++it) {
        cout << (*it) << ' ';
    }
}

int main() {
    solve();
    return 0;
}
