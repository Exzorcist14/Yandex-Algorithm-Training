#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    unordered_map<int, unordered_set<int>> stationsWithLines;

    int P, station;
    for (int i = 0; i < M; ++i) {
        fin >> P;

        for (int j = 0; j < P; ++j) {
            fin >> station;

            stationsWithLines[station].insert(i);
        }
    }

    unordered_map<int, unordered_set<int>> lineConnections;
    for (auto& [sts, ls] : stationsWithLines) {

        for (int l1 : ls) {
            for (int l2 : ls) {

                if (l1 != l2) {
                    lineConnections[l1].insert(l2);
                }
            }
        }
    }

    int start, end;
    fin >> start >> end;

    int transfers = -1;

    queue<pair<int, int>> q;
    unordered_set<int> visited;

    for (auto& l : stationsWithLines[start]) {
        q.emplace(l, 0);

        if (stationsWithLines[end].contains(l)) {
            transfers = 0;
        }

        visited.insert(l);
    }

    while (!q.empty() && transfers == -1) {
        auto [line, dist] = q.front();
        q.pop();

        for (auto& assotiated : lineConnections[line]) {

            if (!visited.contains(assotiated)) {

                visited.insert(assotiated);

                if (!stationsWithLines[end].contains(assotiated)) {
                    q.emplace(assotiated, dist + 1);
                } else {
                    transfers = dist + 1;
                    break;
                }
            }
        }
    }

    cout << transfers << "\n";
}

int main() {
    solve();
    return 0;
}