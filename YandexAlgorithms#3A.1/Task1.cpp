#include <bits/stdc++.h>
using namespace std;

void processRequest(ifstream& fin) {
    int K;
    fin >> K;

    vector<double> A(K);
    for (int i = 0; i < K; ++i) {
        fin >> A[i];
    }

    vector<double> sortedA(K);
    for (int i = 0; i < K; ++i) {
        sortedA[i] = A[i];
    }
    sort(sortedA.begin(), sortedA.end());

    int ans = 1;

    stack<double> storage;
    int ptrMin = 0;

    for (int i = 0; i < K; ++i) {

        while (!storage.empty() && storage.top() == sortedA[ptrMin]) {
            ++ptrMin;
            storage.pop();
        }

        if (A[i] == sortedA[ptrMin]) {
            ++ptrMin;
        } else if (storage.empty() || A[i] <= storage.top()) {
            storage.push(A[i]);
        } else {
            ans = 0;
            break;
        }
    }

    cout << ans << "\n";
}

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    for (int i = 0; i < N; ++i) {
        processRequest(fin);
    }
}

int main() {
    solve();
    return 0;
}