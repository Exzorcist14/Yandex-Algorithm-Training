#include <bits/stdc++.h>

using namespace std;

bool isMultiLine(pair<int, int>& leftA, pair<int, int>& rightA,
                 const vector<vector<int>>& field, int m, int n) {

    int height = 0;

    for (int i = leftA.first; i < m; i++) {
        for (int j = leftA.second; j <= rightA.second; j++) {

            if (field[i][j] != 0) {
                height++;
                break;
            }
        }

        if (height == 2) {
            return true;
        }
    }

    return false;
}


void foundSequence(pair<int, int>& leftA, pair<int, int>& rightA, pair<int, int>& leftB,
                   pair<int, int>& rightB, pair<int, int>& leftBottomA, pair<int, int>& rightBottomA,
                   int& i, int& col, bool& excess, const vector<vector<int>>& field, int m, int n) {

    cout << "<-------> " << i + 1 << " stroka <------------------------------------>" << endl;

    int currLeft = -1;
    int currRight = -1;

    while (currLeft == -1 && col < n) {
        if (field[i][col] != 0) {
            currLeft = col;
            currRight = col;
        }

        col++;
    }

    cout << "Start: " << currLeft << " | " << currRight << endl;

    if (currLeft != -1) {
        if (leftA.second == -1) {
            while (field[i][col] != 0 && col < n) {
                cout << "!!!   Third PRAV" << endl;

                currRight = col;
                col++;
            }
        } else if (leftB.second == -1) {
            while (field[i][col] != 0 && col < n) {
                cout << "!!!   Third PRAV" << endl;

                currRight = col;
                col++;
            }
        } else if (currLeft == leftB.second) {
            while (field[i][col] != 0 && (col <= rightB.second)) {
                cout << "!!!   FIRST PRAV" << endl;
                currRight = col;
                col++;
            }
        } else if (currLeft == leftA.second) {
            while (field[i][col] != 0 && (col <= rightA.second)) {
                cout << "!!!   Second PRAV" << endl;

                currRight = col;
                col++;
            }
        } else {
            if (i + 1 != m) {
                cout << i + 1 + 1 << " ||| " << rightA.second - 1 << " = " << (field[i + 1][rightA.second - 1] == 0) << endl;
                while (field[i][col] != 0 && (field[i + 1][rightA.second - 1] == 0 ? col < n : col < rightA.second)) {
                    cout << "!!!  444 PRAV" << endl;

                    currRight = col;
                    col++;
                }
            } else {
                while (field[i][col] != 0 && col < n) {
                    cout << "!!!   Third PRAV" << endl;

                    currRight = col;
                    col++;
                }
            }


        }

    }

    //переработать границу в цикле выше
    
    cout << "Finish: " << currLeft << " | " << currRight << endl;

    if (currLeft != -1) {
        if (leftA.second == -1) {
            leftA.first = i;
            leftA.second = currLeft;

            rightA.first = i;
            rightA.second = currRight;

            leftBottomA = {i, currLeft};
            rightBottomA = {i, currRight};
        } else if (currLeft == leftA.second && currRight == rightA.second) {
            leftBottomA = {i, currLeft};
            rightBottomA = {i, currRight};
        } else if (currLeft != leftA.second) {
            if (leftB.second == -1) {
                leftB.first = i;
                leftB.second = currLeft;

                rightB.first = i;
                rightB.second = currRight;
            } else if (currLeft != leftB.second) {
                excess = true;
            }
        } else if (currRight != rightA.second) {
            if (rightB.second == -1) {
                leftB.first = i;
                leftB.second = currLeft;

                rightB.first = i;
                rightB.second = currRight;
            } else if (currRight != rightB.second) {
                excess = true;
            }
        }
    }


    cout << "First rect: " << leftA.first << " & " << leftA.second << " | " << rightA.first << " & " << rightA.second << endl;
    cout << "Second rect: " << leftB.first << " & " << leftB.second << " | " << rightB.first << " & " << rightB.second << endl;
    cout << endl;
}

void transform(pair<int, int>& leftA, pair<int, int>& rightA, pair<int, int>& leftBottomA,
               pair<int, int>& rightBottomA, vector<vector<int>>& field, int &m, int& n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (field[i][j] != 0) {
                if (i >= leftA.first && i <= leftBottomA.first && j >= leftA.second && j <= rightA.second) {
                    field[i][j] = 7;
                } else {
                    field[i][j] = 8;
                }
            }
        }
    }
}

void divideAndTransform(pair<int, int>& leftA, pair<int, int>& rightA,
                        vector<vector<int>>& field, int &m, int& n) {

    if (isMultiLine(leftA, rightA, field, m, n)) {
        for (int j = leftA.second; j <= rightA.second; j++) {
            field[leftA.first][j] = 7;
        }

        for (int i = leftA.first + 1; i < m; i++) {
            for (int j = leftA.second; j <= rightA.second; j++) {
                if (field[i][j] != 0) {
                    field[i][j] = 8;
                }
            }
        }
    } else {
        field[leftA.first][leftA.second] = 7;

        for (int j = leftA.second + 1; j <= rightA.second; j++) {
            field[leftA.first][j] = 8;
        }
    }
}

void display(vector<vector<int>>& field, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            switch (field[i][j]) {
                case 0:
                    cout << '.';
                    break;
                case 7:
                    cout << 'a';
                    break;
                case 8:
                    cout << 'b';
                    break;
            }
        }

        cout << "\n";
    }
}


void solve(vector<vector<int>>& field, int m, int n) {
    //<----------------------------------------------------------------->//

    pair<int, int> leftA = {-1, -1};
    pair<int, int> rightA = {-1, -1};
    pair<int, int> leftB = {-1, -1};
    pair<int, int> rightB = {-1, -1};

    pair<int, int> leftBottomA;
    pair<int, int> rightBottomA;

    bool excess = false;
    int col;

    for (int i = 0; i < m; i++) {
        col = 0;

        while (col != n) {
            foundSequence(leftA, rightA, leftB, rightB, leftBottomA, rightBottomA, i, col, excess, field, m, n);
        }

        if (excess) {
            break;
        }
    }

    if (leftA.second != -1 && !excess) {
        if (leftB.second != -1) {
            cout << "YES" << "\n";
            transform(leftA, rightA, leftBottomA, rightBottomA, field, m, n);
            display(field, m, n);
        } else if ((rightA.second != leftA.second) || isMultiLine(leftA, rightA, field, m, n)) {
            cout << "YES" << "\n";
            divideAndTransform(leftA, rightA, field, m, n);
            display(field, m, n);
        } else {
            cout << "NO" << "\n";
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

