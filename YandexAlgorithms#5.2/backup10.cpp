#include <bits/stdc++.h>

using namespace std;

void foundSequence(pair<int, int>& leftA, int& rightA, int& leftB, int& rightB,
                          int& i, int& col, bool& excess, const vector<vector<int>>& field, int m, int n) {

    cout << "<-------> " << i << " stroka <------------------------------------>" << endl;

    int currLeft = -1;
    int currRight = -1;

    while (currLeft == -1 && col < n) {
        if (field[i][col] != 0) {
            currLeft = col;
            currRight = col;
        }

        col++;
    }

    cout << "Start: " << currLeft << " & " << currRight << endl;

    while (field[i][col] != 0 &&
          (rightA != -1 ? col <= max(rightA, rightB) : col < n)) {

        currRight = col;
        col++;
    }

    cout << "Finish: " << currLeft << " & " << currRight << endl;

    if (leftA == -1) {
        leftA = currLeft;
        rightA = currRight;

    } else if (currLeft != leftA) {
        if (leftB == -1) {
            leftB = currLeft;
            rightB = currRight;
        } else if (currLeft != leftB)
            excess = true;

    } else if (currRight != rightA) {
        if (rightB == -1) {
            leftB = currLeft;
            rightB = currRight;
        } else if (currRight != rightB) {
            excess = true;
        }
    }

    cout << "First rect: " << leftA << " & " << rightA << endl;
    cout << "Second rect: " << leftB << " & " << rightB << endl;
    cout << endl;
}

void solve(const vector<vector<int>>& field, int m, int n) {
    cout << "<----------------------------------->" << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j] << " ";
        }

        cout << "\n";
    }
    cout << "<----------------------------------->" << "\n" << "\n";

    //<----------------------------------------------------------------->//

    pair<int, int> leftA = -1;
    pair<int, int> rightA = -1;
    pair<int, int> leftB = -1;
    pair<int, int> rightB = -1;

    int col;
    bool excess = 0;

    for (int i = 0; i < m; i++) {
        col = 0;

        while (col != n) {
            foundSequence(leftA, rightA, leftB, rightB, i, col, excess, field, m, n);
        }

        if (excess) {
            return 0;
        }
    }

    if (leftA.second != -1 && rightA.second != leftA.second) {
        if (leftB.second != -1) {
            cout << "YES" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }
}

int32_t main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> field(m);
    vector<int> temp(n);
    char buff;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> buff;
            if (buff == '#') {
                temp[j] = 1;
            } else {
                temp[j] = 0;
            }
        }

        field[i] = temp;
    }

    solve(field, m, n);

    return 0;
}

