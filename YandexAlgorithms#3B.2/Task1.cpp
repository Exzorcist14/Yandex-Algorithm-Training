#include <bits/stdc++.h>
using namespace std;

class Deque {
private:
    const int VECTOR_SIZE = 1025;

    vector<vector<int>*> blocks;
    int frontB, backB;
    int frontE, backE;
    int dequeSize;

    void expandBack() {
        vector<vector<int>*> newPointers(blocks.size() * 2, nullptr);
        for (int i = frontB; i <= backB; ++i) {
            newPointers[i] = blocks[i];
        }

        blocks = newPointers;
    }

    void compressFront() {
        vector<vector<int>*> newPointers(blocks.size() / 2, nullptr);
        int newFrontB, newBackB;
        int shift = backB - frontB;
        newBackB = newPointers.size() - (blocks.size() - backB);
        newFrontB = newBackB - shift;

        for (int i = newFrontB; i <= newBackB; ++i) {
            newPointers[i] = blocks[i + blocks.size() / 2];
        }

        blocks = newPointers;
        frontB = newFrontB;
        backB = newBackB;
    }

public:
    Deque() {
        for (int i = 0; i < VECTOR_SIZE; i++) {
            blocks.push_back(nullptr);
        }

        frontB = -1;
        backB = -1;
        dequeSize = 0;
    }

    void push(int x) {
        if (backB != -1) {
            if (backE  != VECTOR_SIZE - 1) {
                ++backE;
            } else {
                if (backB == blocks.size() - 1) {
                    expandBack();
                }

                backE = 0;
                ++backB;

                blocks[backB] = new vector<int>(VECTOR_SIZE);
            }

            (*blocks[backB])[backE] = x;
        } else {
            frontB = VECTOR_SIZE / 2;
            backB = VECTOR_SIZE / 2;

            vector<int>* block = new vector<int>(VECTOR_SIZE);
            blocks[backB] = block;

            frontE = VECTOR_SIZE / 2;
            backE = VECTOR_SIZE / 2;

            (*block)[backE] = x;
        }

        ++dequeSize;
    }

    int pop() {
        if (dequeSize > 0) {
            --dequeSize;

            if (frontE < VECTOR_SIZE - 1) {
                frontE++;

                int ans = (*blocks[frontB])[frontE - 1];
                (*blocks[frontB])[frontE - 1] = 0;
                return ans;
            } else {
                frontE = 0;
                frontB++;

                int ans = (*blocks[frontB - 1])[VECTOR_SIZE - 1];
                (*blocks[frontB - 1])[VECTOR_SIZE - 1] = 0;

                if (frontB >= floor(blocks.size() * 0.75)) {
                    compressFront();
                }

                return ans;
            }
        }
    }

    int front() {
        return (*blocks[frontB])[frontE];
    }

    int size() {
        return dequeSize;
    }

    void clear() {
        for (vector<int>* block : blocks) {
            if (block != nullptr) {
                block->clear();
            }
        }

        blocks.clear();
        frontB = -1;
        backB = -1;
        frontE = -1;
        backE = -1;
        dequeSize = 0;
    }
};

void solve() {
    ifstream fin("input.txt");

    Deque deque;

    string word;
    while (fin >> word) {
        if (word == "push") {
            fin >> word;
            deque.push(stoi(word));
            cout << "ok" << "\n";
        } else if (word == "pop") {
            if (deque.size() > 0) {
                cout << deque.pop() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "front") {
            if (deque.size() > 0) {
                cout << deque.front() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "size") {
            cout << deque.size() << "\n";
        } else if (word == "clear") {
            deque.clear();
            cout << "ok" << "\n";
        } else {
            cout << "bye" << "\n";
            break;
        }
    }
}

int main() {
    solve();
    return 0;
}