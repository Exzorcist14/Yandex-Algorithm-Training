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


void foundSequence(bool option, pair<int, int>& leftA, pair<int, int>& rightA, pair<int, int>& leftB,
                   pair<int, int>& rightB, pair<int, int>& leftBottomA, pair<int, int>& rightBottomA,
                   int& i, int& col, bool& excess, vector<vector<int>> field, int m, int n) {

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
        }  else if (currLeft == leftB.second) {
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
        } else if (leftB.second == -1) {
            while (field[i][col] != 0 && (option ? col < n : col < rightA.second)) {
                cout << "!!!   Third PRAV" << endl;

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

    pair<int, int> leftA1 = {-1, -1};
    pair<int, int> rightA1 = {-1, -1};
    pair<int, int> leftB1 = {-1, -1};
    pair<int, int> rightB1 = {-1, -1};

    pair<int, int> leftBottomA1;
    pair<int, int> rightBottomA1;

    bool excess1 = false;
    int col;

    for (int i = 0; i < m; i++) {
        col = 0;

        while (col != n) {
            foundSequence(0, leftA1, rightA1, leftB1, rightB1, leftBottomA1, rightBottomA1, i, col, excess1, field, m, n);
        }

        if (excess1) {
            break;
        }
    }

    pair<int, int> leftA2 = {-1, -1};
    pair<int, int> rightA2 = {-1, -1};
    pair<int, int> leftB2 = {-1, -1};
    pair<int, int> rightB2 = {-1, -1};

    pair<int, int> leftBottomA2;
    pair<int, int> rightBottomA2;

    bool excess2 = false;
    col = 0;

    for (int i = 0; i < m; i++) {
        col = 0;

        while (col != n) {
            foundSequence(1, leftA2, rightA2, leftB2, rightB2, leftBottomA2, rightBottomA2, i, col, excess2, field, m, n);
        }

        if (excess2) {
            break;
        }
    }

    if (leftA1.second != -1) {
        if (!excess1) {
            if (leftB1.second != -1) {
                cout << "YES" << "\n";
                transform(leftA1, rightA1, leftBottomA1, rightBottomA1, field, m, n);
                display(field, m, n);
            } else if ((rightA1.second != leftA1.second) || isMultiLine(leftA1, rightA1, field, m, n)) {
                cout << "YES" << "\n";
                divideAndTransform(leftA1, rightA1, field, m, n);
                display(field, m, n);
            } else {
                cout << "NO" << "\n";
            }
        } else if (!excess2) {
            if (leftB2.second != -1) {
                cout << "YES" << "\n";
                transform(leftA2, rightA2, leftBottomA2, rightBottomA2, field, m, n);
                display(field, m, n);
            } else if ((rightA2.second != leftA2.second) || isMultiLine(leftA2, rightA2, field, m, n)) {
                cout << "YES" << "\n";
                divideAndTransform(leftA2, rightA2, field, m, n);
                display(field, m, n);
            } else {
                cout << "NO" << "\n";
            }
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

