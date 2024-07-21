#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int root, int tail) {
    int ptr = root;

    while (true) {
        if (ptr * 2 + 1 <= tail &&
            a[ptr * 2 + 1] > a[ptr] && (ptr * 2 + 2 > tail || a[ptr * 2 + 1] > a[ptr * 2 + 2])) {

            swap(a[ptr], a[ptr * 2 + 1]);
            ptr = ptr * 2 + 1;
        } else if (ptr * 2 + 2 <= tail && a[ptr * 2 + 2] > a[ptr]) {

            swap(a[ptr], a[ptr * 2 + 2]);
            ptr = ptr * 2 + 2;
        } else {
            break;
        }
    }
}

void heapSort(vector<int>& a) {
    for (int i = a.size() / 2 - 1; i >= 0; --i) {
        heapify(a, i, a.size() - 1);
    }

    for (int i = a.size() - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }
}

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        fin >> array[i];
    }

    heapSort(array);

    for (auto& elem : array) {
        cout << elem << " ";
    } cout << "\n";
}

int main() {
    solve();
    return 0;
}