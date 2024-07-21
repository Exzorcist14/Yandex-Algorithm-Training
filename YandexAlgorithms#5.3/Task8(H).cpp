#include <bits/stdc++.h>

#define int long long

using namespace std;

struct VectorHash {
    template<typename T>
    size_t operator()(const vector<T>& v) const {
        size_t seed = 0;

        for (const T& elem : v) {
            hash<T> hasher;
            seed ^= hasher(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

        return seed;
    }
};

vector<int> calculateVector(const vector<int>& match) {
    return {match[2] - match[0], match[3] - match[1]};
}

vector<int> calculateOffset(const vector<int>& match, const vector<int>& potentialOverlap) {
    return {potentialOverlap[0] - match[0], potentialOverlap[1] - match[1]};
}

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

void normalize(vector<int>& vect) {
    if (vect[0] == vect[2] && vect[3] < vect[1]) {
        swap(vect[1], vect[3]);
    } else if (vect[1] == vect[3] && vect[2] < vect[0]) {
        swap(vect[0], vect[2]);
    } else if (vect[0] > vect[2] && vect[1] > vect[3]) {
        swap(vect[0], vect[2]);
        swap(vect[1], vect[3]);
    } else if (vect[0] < vect[2] && vect[1] > vect[3]) {
        swap(vect[0], vect[2]);
        swap(vect[1], vect[3]);
    }
}

[[noreturn]] void solve() {
    int n;
    cin >> n;

    unordered_map<vector<int>, vector<int>, VectorHash> A;
    vector<int> temp(4);
    for (int i = 0; i < n; i++) {
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        normalize(temp);

        A[temp] = calculateVector(temp);
    }

    unordered_map<vector<int>,  vector<vector<int>>,  VectorHash> B;
    for (int i = 0; i < n; i++) {
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        normalize(temp);

        B[calculateVector(temp)].push_back(temp);
    }

    unordered_map<vector<int>, int, VectorHash> offsets;
    for (auto& match : A) {
        for (auto& potentialOverlap : B[match.second]) {
            offsets[calculateOffset(match.first, potentialOverlap)]++;
        }
    }

    int maxOverlaps = 0;
    for (auto& offset : offsets) {
        maxOverlaps = max(offset.second, maxOverlaps);
    }

    cout << n - maxOverlaps << "\n";
}

int32_t main() {
    solve();

    return 0;
}
