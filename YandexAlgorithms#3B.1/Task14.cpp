#include <bits/stdc++.h>

using namespace std;

void solve() {
    ifstream fin("input.txt");
    int n, carriege;
    fin >> n;

    stack<int> deadEnd;
    int lastCarriegeInTrack2 = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        fin >> carriege;

        while (deadEnd.size() != 0 && deadEnd.top() == lastCarriegeInTrack2 + 1) {
            lastCarriegeInTrack2 = deadEnd.top();
            deadEnd.pop();
        }

        if (carriege == lastCarriegeInTrack2 + 1) {
            lastCarriegeInTrack2 = carriege;
        } else if (deadEnd.size() == 0 || carriege < deadEnd.top()){
            deadEnd.push(carriege);
        } else {
            flag = false;
        }
    }

    if (flag) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    solve();
    return 0;
}
