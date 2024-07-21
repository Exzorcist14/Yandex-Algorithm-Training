#include <bits/stdc++.h>

#define int long long

using namespace std;

int findLength(vector<int>& seq, int widthPart, int minWidth) {
    int l = -1000;

    if (minWidth <= widthPart) {
        l = 1;
        int currW = 0;
        int maxWordL = 0;

        for (int i = 0; i < seq.size(); i++) {
            currW += seq[i] + 1;

            if (currW - 1 > widthPart) {
                l++;
                currW = seq[i] + 1;
            }
        }
    }

    return l;
}

int findMax(vector<int>& seq) {
    int maxN = 0;

    for (auto& number : seq) {
        maxN = max(number, maxN);
    }

    return maxN;
}

pair<int, int> leftBinSearch(int w, int minWidthA, int minWidthB, vector<int>& A, vector<int>& B) {

    int l = minWidthA;
    int r = w - minWidthB;
    int mid;

    while (l != r) {
        mid = (l + r) / 2;

        if (findLength(A, mid, minWidthA) <= findLength(B, w - mid, minWidthB)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int enoughL = max(findLength(A, l, minWidthA), findLength(B, w - l, minWidthB));
    int diffL = abs(findLength(A, l, minWidthA) - findLength(B, w - l, minWidthB));
    return {enoughL, diffL};
}

pair<int, int> rightBinSearch(int w, int minWidthA, int minWidthB, vector<int>& A, vector<int>& B) {

    int l = minWidthA;
    int r = w - minWidthB;
    int mid;

    while (l != r) {
        mid = (l + r + 1) / 2;

        if (findLength(B, mid, minWidthB) <= findLength(A, w - mid, minWidthA)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int enoughL = max(findLength(A, l, minWidthA), findLength(B, w - l, minWidthB));
    int diffL = abs(findLength(A, l, minWidthA) - findLength(B, w - l, minWidthB));
    return {enoughL, diffL};
}

void solve() {
    ifstream fin("input.txt");

    int w, n, m;
    fin >> w >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        fin >> A[i];
    }

    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        fin >> B[i];
    }

    int minWidthA = findMax(A);
    int minWidthB = findMax(B);

    pair<int, int> leftSearchResult = leftBinSearch(w, minWidthA, minWidthB, A, B);
    pair<int, int> rightSearchResult = rightBinSearch(w, minWidthA, minWidthB, A, B);

    if (leftSearchResult.second < rightSearchResult.second) {
        cout << leftSearchResult.first << "\n";
    } else {
        cout << rightSearchResult.first << "\n";
    }
}

int32_t main() {
    solve();
    return 0;
}
