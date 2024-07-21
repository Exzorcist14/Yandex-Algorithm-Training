#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<pair<int, int>> orders(N + 1);
    for (int i = 1; i <= N; ++i) {
        fin >> orders[i].first >> orders[i].second;
    }

    vector<vector<pair<int, int>>> dp(N + 1, vector<pair<int, int>>(2));
    for (int i = 1; i <= N; ++i) {

        if (dp[i - 1][0].first <= dp[i - 1][1].first) {
            dp[i][0].first = dp[i - 1][0].first + orders[i].first;
            dp[i][0].second = 0;
        } else {
            dp[i][0].first = dp[i - 1][1].first + orders[i].first;
            dp[i][0].second = 1;
        }

        if (dp[i - 1][0].first <= dp[i - 1][1].first) {
            dp[i][1].first = dp[i - 1][0].first + orders[i].second;
            dp[i][1].second = 0;
        } else {
            dp[i][1].first = dp[i - 1][1].first + orders[i].second;
            dp[i][1].second = 1;
        }
    }

    vector<int> distribution;
    
    int i = N;
    int j;
    
    if (dp[i][0].first < dp[i][1].first) {
        distribution.push_back(1);
        j = dp[i][0].second;
        --i;
    } else {
        distribution.push_back(2);
        j = dp[i][1].second;
        --i;
    }
    
    while (i != 0) {
        distribution.push_back(1 + j);
        --i;
        j = dp[i][j].second;
    }

    for (int k = N - 1; k >= 0; --k) {
        cout << distribution[k] << " ";
    }
}

int main() {
    solve();
    return 0;
}