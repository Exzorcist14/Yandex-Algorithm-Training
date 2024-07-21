#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    if (N != 0) {
        vector<int> day(N + 1);
        for (int i = 1; i <= N; ++i) {
            fin >> day[i];
        }

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 50000));
        dp[1][day[1] > 100] = day[1];

        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {

                if (day[i] > 100) {
                    dp[i][j] = min((j - 1 >= 0 ? dp[i - 1][j - 1] : 50000) + day[i], (j + 1 <= N ? dp[i - 1][j + 1] : 50000));
                } else {
                    dp[i][j] = min(dp[i - 1][j] + day[i], (j + 1 <= N ? dp[i - 1][j + 1] : 50000));
                }
            }
        }


        int indMin = N;
        for (int j = N; j >= 0; --j) {
            if (dp[N][j] < dp[N][indMin]) {
                indMin = j;
            }
        }

        int i = N;
        int j = indMin;

        vector<int> couponDays;
        while (!(i == 1 && j == (day[1] > 100))) {
            if (day[i] > 100) {

                if (j + 1 <= N && dp[i - 1][j + 1] == dp[i][j] && (j - 1 < 0 || dp[i - 1][j - 1] != dp[i][j])) {
                    couponDays.push_back(i);
                    i = i - 1;
                    j = j + 1;
                } else {
                    i = i - 1;
                    j = j - 1;
                }
            } else {
                if (j + 1 <= N && dp[i - 1][j + 1] == dp[i][j] && dp[i - 1][j] != dp[i][j]) {
                    couponDays.push_back(i);
                    i = i - 1;
                    j = j + 1;
                } else {
                    i = i - 1;
                }
            }
        }

        cout << dp[N][indMin] << "\n";
        cout << indMin << " " << couponDays.size() << "\n";
        for (auto it = couponDays.rbegin(); it != couponDays.rend(); ++it) {
            cout << (*it) << " ";
        }
    } else {
        cout << 0 << "\n";
        cout << 0 << " " << 0 << "\n";
    }
}

int main() {
    solve();
    return 0;
}