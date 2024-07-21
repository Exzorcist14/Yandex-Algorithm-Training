#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> op(N + 1);
    vector<int> prev(N + 1);
    op[0] = -1; op[1] = 0;
    prev[0] = -1; prev[1] = 0; //ALERT

    for (int i = 2; i <= N; ++i) {
        op[i] = op[i - 1] + 1;
        prev[i] = i - 1;

        if ((i / 2) * 2 == i) {
            if (op[i / 2] < op[i]) {
                op[i] = op[i / 2] + 1;
                prev[i] = i / 2;
            }
        }

        if ((i / 3) * 3 == i) {
            if (op[i / 3] < op[i]) {
                op[i] = op[i / 3] + 1;
                prev[i] = i / 3;
            }
        }
    }

    vector<int> ans;
    int curr = N;
    while (curr != 0) {
        ans.push_back(curr);
        curr = prev[curr];
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[ans.size() - i - 1] << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}