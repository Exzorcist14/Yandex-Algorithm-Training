#include <bits/stdc++.h>

#define int long long

using namespace std;

set<int> findIntersection(unordered_set<int> cubesA, unordered_set<int> cubesB) {
    set<int> intersection;

    for (int element : cubesA) {
        if (cubesB.contains(element)) {
            intersection.insert(element);
        }
    }

    return intersection;
}

set<int> findDifference(unordered_set<int> set1, set<int> set2) {
    set<int> difference;

    for (int element : set1) {
        if (!set2.contains(element)) {
            difference.insert(element);
        }
    }

    return difference;
}

void solve(unordered_set<int> cubesA, unordered_set<int> cubesB) {
    set<int> intersection = findIntersection(cubesA, cubesB);

    cout << intersection.size() << "\n";
    for (int element : intersection) {
        cout << element << " ";
    }
    cout << "\n";

    set<int> difference = findDifference(cubesA, intersection);

    cout << difference.size() << "\n";
    for (int element : difference) {
        cout << element << " ";
    }
    cout << "\n";

    difference = findDifference(cubesB, intersection);

    cout << difference.size() << "\n";
    for (int element : difference) {
        cout << element << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nA, nB;
    cin >> nA >> nB;

    unordered_set<int> cubesA;
    int temp;
    for (int i = 0; i < nA; i++) {
        cin >> temp;
        cubesA.insert(temp);
    }

    unordered_set<int> cubesB;
    for (int i = 0; i < nB; i++) {
        cin >> temp;
        cubesB.insert(temp);
    }

    solve(cubesA, cubesB);

    return 0;
}