#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, k;
    fin >> N >> k;

    vector<int> board(N, 0);
    board[0] = 1;

    if (k < N) {
        vector<int> window(k, 0);
        window[0] = 1;
        int s = 1;

        for (int i = 0; i < min(k, N); ++i) {
            for (int j = 0; j < i; ++j) {
                board[i] += board[j];
                window[i] += board[j];
                s += board[j];
            }
        }

        for (int i = k; i < N; ++i) {
            board[i] = s;
            s -= window[i % k];
            s += board[i];
            window[i % k] = board[i];
        }
    } else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                board[i] += board[j];
            }
        }
    }

    cout << board.back() << "\n";
}

int main() {
    solve();
    return 0;
}