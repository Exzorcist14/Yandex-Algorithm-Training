#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, W;
    fin >> N >> W;

    vector<pair<pair<int, int>, int>> tasks(N + 1);
    for (int i = 1; i <= N; ++i) {
        fin >> tasks[i].first.first >> tasks[i].first.second;
        tasks[i].second = i;
    }

    sort(tasks.begin(), tasks.end());

    map<int, vector<int>> workers;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> completedTasks;

    workers[1].push_back(tasks[1].second);
    completedTasks.emplace(tasks[1].first.first + tasks[1].first.second - 1, 1);

    for (int i = 2; i <= N; ++i) {

        if (tasks[i].first.first > completedTasks.top().first) {
            workers[completedTasks.top().second].push_back(tasks[i].second);
            completedTasks.pop();
            completedTasks.emplace(tasks[i].first.first + tasks[i].first.second, completedTasks.top().second);
        } else {
            workers[workers.size() + 1].emplace_back(tasks[i].second);
            completedTasks.emplace(tasks[i].first.first + tasks[i].first.second, workers.size() - 1);
        }
    }

    cout << workers.size() << "\n";
    for (auto& [worker, workersTasks] : workers) {
        for (auto& task : workersTasks) {
            cout << task << " ";
        }
    }
}

int main() {
    solve();
    return 0;
}