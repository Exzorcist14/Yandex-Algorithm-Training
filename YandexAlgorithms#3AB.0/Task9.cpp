#include <bits/stdc++.h>
using namespace std;

void processRequest(int x1, int y1, int x2, int y2, const vector<vector<int>>& prefSum) {
    cout << prefSum[x2][y2] - prefSum[x1 - 1][y2] - prefSum[x2][y1 - 1]
                + prefSum[x1 - 1][y1 - 1] << "\n";
}

void calculatePrefSums(vector<vector<int>>& prefSum, const vector<vector<int>>& matrix,
                            const int& N, const int& M) {

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefSum[i][j] = matrix[i][j] + prefSum[i - 1][j] + prefSum[i][j - 1]
                    - prefSum[i - 1][j - 1];
        }
    }
}

void solve() {
    ifstream fin("input.txt");

    int N, M, K;
    fin >> N >> M >> K;

    vector<vector<int>> matrix(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            fin >> matrix[i][j];
        }
    }

    vector<vector<int>> prefSum(N + 1, vector<int>(M + 1));
    calculatePrefSums(prefSum, matrix, N, M);

    int x1, y1, x2, y2;
    while (K --> 0) {
        fin >> x1 >> y1 >> x2 >> y2;
        processRequest(x1, y1, x2, y2, prefSum);
    }
}

int main() {
    solve();
    return 0;
}