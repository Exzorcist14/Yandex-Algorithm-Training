#include <bits/stdc++.h>

using namespace std;

int pack(int x, int y) {
    return x * 10 + y;
}

bool insideField(int x, int y) {
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
        return true;
    }

    return false;
}

void beatCells(const vector<vector<char>>& field, char figure, int x, int y, unordered_set<int>& beatenCells) {
    beatenCells.insert(pack(x, y)); //Клетка не пуста, поэтому "количество пустых клеток" уменьшается на 1

    if (figure == 'R') {
        for (int offset = -1; offset >= -7; offset--) {
            if (insideField(x + offset, y)) {
                if (field[x + offset][y] == '*') {
                    beatenCells.insert(pack(x + offset, y));
                } else {
                    break;
                }
            }
        }

        for (int offset = 1; offset <= 7; offset++) {
            if (insideField(x + offset, y)) {
                if (field[x + offset][y] == '*') {
                    beatenCells.insert(pack(x + offset, y));
                } else {
                    break;
                }
            }
        }

        for (int offset = -1; offset >= -7; offset--) {
            if (insideField(x, y + offset)) {
                if (field[x][y + offset] == '*') {
                    beatenCells.insert(pack(x, y + offset));
                } else {
                    break;
                }
            }
        }

        for (int offset = 1; offset <= 7; offset++) {
            if (insideField(x, y + offset)) {
                if (field[x][y + offset] == '*') {
                    beatenCells.insert(pack(x, y + offset));
                } else {
                    break;
                }
            }
        }
    } else {
        for (int offset = -1; offset >= -7; offset--) {
            if (insideField(x + offset, y + offset)) {
                if (field[x + offset][y + offset] == '*') {
                    beatenCells.insert(pack(x + offset, y + offset));
                } else {
                    break;
                }
            }
        }

        for (int offset = 1; offset <= 7; offset++) {
            if (insideField(x + offset, y + offset)) {
                if (field[x + offset][y + offset] == '*') {
                    beatenCells.insert(pack(x + offset, y + offset));
                } else {
                    break;
                }
            }
        }

        for (int offset = -1; offset >= -7; offset--) {
            if (insideField(x - offset, y + offset)) {
                if (field[x - offset][y + offset] == '*') {
                    beatenCells.insert(pack(x - offset, y + offset));
                } else {
                    break;
                }
            }
        }

        for (int offset = 1; offset <= 7; offset++) {
            if (insideField(x - offset, y + offset)) {
                if (field[x - offset][y + offset] == '*') {
                    beatenCells.insert(pack(x - offset, y + offset));
                } else {
                    break;
                }
            }
        }
    }
}

void solve(const vector<vector<char>>& field) {
    unordered_set<int> beatenCells;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] != '*') {
                beatCells(field, field[i][j], i, j, beatenCells);
            }
        }
    }

    cout << 64 - beatenCells.size() << "\n";
}

int32_t main() {
    vector<vector<char>> field(8);
    vector<char> line(8);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> line[j];
        }

        field[i] = line;
    }

    solve(field);

    return 0;
}