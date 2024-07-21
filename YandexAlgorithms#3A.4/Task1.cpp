#include <bits/stdc++.h>
#define int double
using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);

        return hash1 ^ hash2;
    }
};

const vector<int> dx = {-1,  1, 2,  2};
const vector<int> dy = { 2,  2, 1, -1};

bool onBoard(int i, int j, int N, int M) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void dfs(pair<int, int> v1, unordered_map<pair<int, int>, int, PairHash>& dp,
         unordered_set<pair<int, int>, PairHash>& visited,
         unordered_map<pair<int, int>, unordered_set<pair<int, int>, PairHash>, PairHash>&
                 reversedGraph) {

    visited.insert(v1);

    for (auto& v2 : reversedGraph[v1]) {

        if (!visited.contains(v2)) {
            dfs(v2, dp, visited, reversedGraph);
        }

        dp[v1] += dp[v2];
    }
}

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    unordered_map<pair<int, int>, unordered_set<pair<int, int>, PairHash>, PairHash> graph;
    unordered_map<pair<int, int>, unordered_set<pair<int, int>, PairHash>, PairHash> reversedGraph;
    unordered_set<pair<int, int>, PairHash> visited;
    visited.insert({0, 0});

    queue<pair<int, int>> queueForConstruction;
    queueForConstruction.emplace(0, 0);

    int i, j, newI, newJ;
    while (!queueForConstruction.empty()) {
        i = queueForConstruction.front().first;
        j = queueForConstruction.front().second;
        queueForConstruction.pop();

        for (int sh = 0; sh < 4; ++sh) {

            newI = i + dx[sh];
            newJ = j + dy[sh];

            if (onBoard(newI, newJ, N, M)) {
                graph[{i, j}].insert({newI, newJ});
                reversedGraph[{newI, newJ}].insert({i, j});

                if (!visited.contains({newI, newJ})) {
                    visited.insert({newI, newJ});
                    queueForConstruction.emplace(newI, newJ);
                }
            }
        }
    }

    unordered_map<pair<int, int>, int, PairHash> dp;
    dp[{0, 0}] = 1;

    visited.clear();

    dfs({N - 1, M - 1}, dp, visited, reversedGraph);

    cout << dp[{N - 1, M - 1}] << "\n";
}

int32_t main() {
    solve();
    return 0;
}