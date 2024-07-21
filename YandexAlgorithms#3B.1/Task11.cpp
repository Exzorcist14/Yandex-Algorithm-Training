#include <bits/stdc++.h>

#define int long long

using namespace std;

struct StackNode {
    StackNode* prev;
    int n;
};

class Stack {
private:
    StackNode* backNode;
    int stackSize;
public:
    Stack() {
        backNode = nullptr;
        stackSize = 0;
    }

    void push(int n) {
        StackNode* newNode = new StackNode();
        newNode->prev = backNode;
        newNode->n = n;

        backNode = newNode;
        ++stackSize;
    }

    int pop() {
        if (stackSize > 0) {
            StackNode* extraNode = backNode;

            int n = backNode->n;
            backNode = backNode->prev;
            --stackSize;

            delete extraNode;

            return n;
        }
    }

    int back() {
        if (stackSize > 0) {
            return backNode->n;
        }
    }

    int size() {
        return stackSize;
    }

    void clear() {
        while (backNode) {
            StackNode* extraNode = backNode;

            backNode = backNode->prev;
            --stackSize;

            delete extraNode;
        }
    }
};

void solve() {
    Stack stack;

    ifstream fin("input.txt");
    string word;

    while (fin >> word) {

        if (word == "push") {
            fin >> word;
            stack.push(stoi(word));
            cout << "ok" << "\n";
        } else if (word == "pop") {
            if (stack.size() != 0) {
                cout << stack.pop() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "back") {
            if (stack.size() != 0) {
                cout << stack.back() << "\n";
            } else {
                cout << "error" << "\n";
            }
        } else if (word == "size") {
            cout << stack.size() << "\n";
        } else if (word == "clear") {
            stack.clear();
            cout << "ok" << "\n";
        } else {
            cout << "bye" << "\n";
            break;
        }
    }
}

int32_t main() {
    solve();
    return 0;
}
