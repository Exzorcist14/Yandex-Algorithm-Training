#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);

        return hash1 ^ hash2;
    }
};

const vector<int> dx = {1, 2,  2,  1, -1, -2, -2, -1};
const vector<int> dy = {2, 1, -1, -2, -2, -1,  1,  2};

bool onField(int x, int y, int n, int m) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void solve() {
    ifstream fin("input.txt");

    int N, M, S, T, Q;
    fin >> N >> M >> S >> T >> Q;

    vector<pair<int, int>> fleas(Q);
    for (int i = 0; i < Q; ++i) {
        fin >> fleas[i].first >> fleas[i].second;
    }

    unordered_map<pair<int, int>, int, PairHash> dist;
    dist[{S, T}] = 0;

    queue<pair<int, int>> q;
    q.emplace(S, T);

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int sh = 0; sh < 8; ++sh) {

            int newI = i + dx[sh];
            int newJ = j + dy[sh];

            if (onField(newI, newJ, N, M) && !dist.contains({newI, newJ})) {

                dist[{newI, newJ}] = dist[{i, j}] + 1;
                q.emplace(newI, newJ);
            }
        }
    }

    int ans = 0;

    for (auto& flea : fleas) {
        if (dist.contains(flea)) {
            ans += dist[flea];
        } else {
            ans = -1;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}