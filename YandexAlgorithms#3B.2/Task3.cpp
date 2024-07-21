#include <bits/stdc++.h>
using namespace std;

class Deque {
private:
    const int VECTOR_SIZE = 1025;

    vector<vector<int>*> blocks;
    int frontB, backB;
    int frontE, backE;
    int dequeSize;

    void expandFront() {
        vector<vector<int>*> newPointers(blocks.size() * 2, nullptr);
        int newFrontB, newBackB;
        int shift = backB - frontB;
        newBackB = newPointers.size() - (blocks.size() - backB);
        newFrontB = newBackB - shift;

        for (int i = frontB; i <= backB; ++i) {
            newPointers[i + blocks.size()] = blocks[i];
        }

        blocks = newPointers;
        frontB = newFrontB;
        backB = newBackB;
    }

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

    void compressBack() {
        vector<vector<int>*> newPointers(blocks.size() / 2, nullptr);
        for (int i = frontB; i <= backB; i++) {
            newPointers[i] = blocks[i];
        }

        blocks = newPointers;
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

    void push_front(int x) {
        if (frontB != -1) {
            if (frontE != 0) {
                --frontE;
            } else {
                if (frontB == 0) {
                    expandFront();
                }

                frontE = VECTOR_SIZE - 1;
                --frontB;

                blocks[frontB] = new vector<int>(VECTOR_SIZE);
            }

            (*blocks[frontB])[frontE] = x;
        } else {
            frontB = VECTOR_SIZE / 2;
            backB = VECTOR_SIZE / 2;

            vector<int>* block = new vector<int>(VECTOR_SIZE);
            blocks[frontB] = block;

            frontE = VECTOR_SIZE / 2;
            backE = VECTOR_SIZE / 2;

            (*block)[frontE] = x;
        }

        ++dequeSize;
    }

    void push_back(int x) {
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

    int pop_front() {
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

    int pop_back() {
        if (dequeSize > 0) {
            --dequeSize;

            if (backE > 0) {
                --backE;

                int ans = (*blocks[backB])[backE + 1];
                (*blocks[backB])[backE + 1] = 0;
                return ans;
            } else {
                backE = VECTOR_SIZE - 1;
                --backB;

                int ans = (*blocks[backB + 1])[0];
                (*blocks[backB + 1])[0] = 0;

                if (backB <= floor(blocks.size() * 0.25)) {
                    compressBack();
                }

                return ans;
            }
        }
    }

    int front() {
        return (*blocks[frontB])[frontE];
    }

    int back() {
        return (*blocks[backB])[backE];
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
            deque.push_front(stoi(word));
            cout << "ok" << "\n";
        } else if (word == "push_back") {
            fin >> word;
            deque.push_back(stoi(word));
            cout << "ok" << "\n";
        } else if (word == "pop_front") {
            if (deque.size() > 0) {
                cout << deque.pop_front() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "pop_back") {
            if (deque.size() > 0) {
                cout << deque.pop_back() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "front") {
            if (deque.size() > 0) {
                cout << deque.front() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "back") {
            if (deque.size() > 0) {
                cout << deque.back() << "\n";
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