#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> heap;

    void insert(int k) {
        heap.push_back(k);

        //Просеем вверх
        int ptr = heap.size() - 1;
        while (ptr != 0 && heap[ptr] > heap[(ptr - 1) / 2]) {
            swap(heap[ptr], heap[(ptr - 1) / 2]);
            ptr = (ptr - 1) / 2;
        }
    }

    int extract() {
        int ans = heap.front();

        swap(heap.front(), heap.back());

        //Просеем вниз
        int ptr = 0;
        while (true) {
            if (ptr * 2 + 1 < heap.size() - 1 && heap[ptr * 2 + 1] > heap[ptr] && (ptr * 2 + 2 >= heap.size() - 1 || heap[ptr * 2 + 1] > heap[ptr * 2 + 2])){
                swap(heap[ptr], heap[ptr * 2 + 1]);
                ptr = ptr * 2 + 1;
            } else if (ptr * 2 + 2 < heap.size() - 1 && heap[ptr] < heap[ptr * 2 + 2]) {
                swap(heap[ptr], heap[ptr * 2 + 2]);
                ptr = ptr * 2 + 2;
            } else {
                break;
            }
        }

        heap.pop_back();
        return ans;
    }
};

void solve() {
    ifstream fin("input.txt");

    Heap heap;

    int n;
    fin >> n;

    int op;
    while (n --> 0) {
        fin >> op;

        if (op == 0) {
            fin >> op;
            heap.insert(op);
        } else {
            cout << heap.extract() << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
