#include <bits/stdc++.h>

using namespace std;

int performOperation(int& a, int& b, char& operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
}

bool isNumber(char& symb) {
    if (symb >= 48 && symb <= 57) {
        return true;
    } return false;
}

void solve() {
    ifstream fin("input.txt");

    stack<int> exp;
    char symb;

    int operand1;
    int operand2;

    while (fin >> symb) {
        if (isNumber(symb)) {
            exp.push(symb - '0');
        } else {
            operand2 = exp.top();
            exp.pop();
            operand1 = exp.top();
            exp.pop();
            exp.push(performOperation(operand1, operand2, symb));
        }
    }

    cout << exp.top() << "\n";
}

int main() {
    solve();
    return 0;
}
