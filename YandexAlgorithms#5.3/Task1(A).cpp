#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(const map<string, int>& friendsSongs, int n) {
    //Словарь friendsSongs содержит пары название песни - скольким людям она нравится

    vector<string> ans;

    for (auto& song : friendsSongs) {
        //Если песня нравится всем

        if (song.second == n) {
            ans.push_back(song.first);
        }
    }

    cout << ans.size() << "\n";
    for (auto& songName : ans) {
        cout << songName << " ";
    }
    cout << "\n";
}

int32_t main() {
    int n;
    cin >> n;

    int k;
    string song;
    map<string, int> friendsSongs;

    for (int i = 0; i < n; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> song;

            friendsSongs[song]++;
        }
    }

    solve(friendsSongs, n);

    return 0;
}
