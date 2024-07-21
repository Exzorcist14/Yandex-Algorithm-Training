#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;

    unordered_map<int, unordered_set<int>> graph;

    int temp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> temp;

            if (temp == 1) {
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
    }

    int start, end;
    fin >> start >> end;

    if (start != end) {
        queue<int> q;
        q.push(start);

        vector<int> dist(n + 1, INT_MAX);
        dist[start] = 0;

        int ans = INT_MAX;
        int v1;
        while (!q.empty()) {
            v1 = q.front();
            q.pop();

            for (auto& v2 : graph[v1]) {

                if (dist[v2] == INT_MAX) {
                    dist[v2] = dist[v1] + 1;

                    if (v2 == end) {
                        ans = dist[v2];
                    } else {
                        q.push(v2);
                    }
                }
            }
        }

        cout << (ans != INT_MAX ? ans : -1) << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    solve();
    return 0;
}
