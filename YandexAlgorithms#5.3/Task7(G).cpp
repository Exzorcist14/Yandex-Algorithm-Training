#include <bits/stdc++.h>

#define int long long

using namespace std;

struct pairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return (hash1 + hash2) % 1000000;
    }
};

void input(int& N, unordered_set<pair<int, int>, pairHash>& points) {
    cin >> N;

    int x, y;
    while (N --> 0) {
        cin >> x >> y;
        points.insert({x, y});
    }
}

vector<pair<int, int>> findReflections(const pair<int, int>& point1, const pair<int, int>& point2,
                                       const unordered_set<pair<int, int>, pairHash>& points) {

    int offsetX = point2.first - point1.first;
    int offsetY = point2.second - point1.second;

    vector<pair<int, int>> addVertices1;
    vector<pair<int, int>> addVertices2;

    //Отражение вверх
    if (!points.contains({point1.first - offsetY, point1.second + offsetX})) {
        addVertices1.push_back({point1.first - offsetY, point1.second + offsetX});
    }

    if (!points.contains({point2.first - offsetY, point2.second + offsetX})) {
        addVertices1.push_back({point2.first - offsetY, point2.second + offsetX});
    }

    //Отражение вниз
    if (!points.contains({point1.first + offsetY, point1.second - offsetX})) {
        addVertices2.push_back({point1.first + offsetY, point1.second - offsetX});
    }

    if (!points.contains({point2.first + offsetY, point2.second - offsetX})) {
        addVertices2.push_back({point2.first + offsetY, point2.second - offsetX});
    }

    if (addVertices1.size() < addVertices2.size()) {
        return addVertices1;
    } else {
        return addVertices2;
    }
}

void findAddVerticesToOne(vector<pair<int, int>>& addVertices,
                          const unordered_set<pair<int, int>, pairHash> points) {

    for (auto& startingPoint : points) {
        addVertices.push_back({startingPoint.first, startingPoint.second + 1});
        addVertices.push_back({startingPoint.first + 1, startingPoint.second + 1});
        addVertices.push_back({startingPoint.first + 1, startingPoint.second});
    }
}

void solve() {
    int N;
    unordered_set<pair<int, int>, pairHash> points;
    input(N, points);

    vector<pair<int, int>> addVertices(3);

    if (N != 1) {
        //Выбор опорной точки
        for (auto& referencePoint: points) {

            //Выбор пары
            for (auto& currentPoint: points) {

                //Парная точка должна отличаться от опорной
                if (currentPoint != referencePoint) {

                    vector<pair<int, int>> currentAddVertices = findReflections(referencePoint, currentPoint, points);

                    if (addVertices.size() > currentAddVertices.size()) {
                        addVertices = currentAddVertices;
                    }
                }
            }
        }
    } else {
        findAddVerticesToOne(addVertices, points);
    }

    cout << addVertices.size() << "\n";
    for (auto& vertice : addVertices) {
        cout << vertice.first << " " << vertice.second << "\n";
    }
}


int32_t main() {
    solve();

    return 0;
}
