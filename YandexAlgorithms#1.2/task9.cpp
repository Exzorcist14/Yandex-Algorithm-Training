#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(vector<int> field, int X, int Y, int n) {
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x -= 1;
        y -= 1;

        int absCoordMine = x * Y + y;
        field[absCoordMine] = -1; // -1 ~ присутствию мины. При выводе будем отображать, как *

        int absCoordAdj;
        int currS;
        int currC;

        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                absCoordAdj = (x + j) * Y + (y + k);
                currS = absCoordAdj / X;
                currC = absCoordAdj / Y;

                if (((x + j) >= 0 && (x + j) < X && (y + k) >= 0 && (y + k) < Y)  && //проверка смежности
                    (field[absCoordAdj] != -1)) { //проверка на отсутствие мины

                    field[absCoordAdj] += 1;
                }
            }
        }
    }

    for (int i = 0; i < field.size(); i++) {
        if (i % Y == 0) {
            if (i > 0) {
                cout << "\n";
            }

            if (field[i] == -1) {
                cout << "*";
            }

            else {
                cout << field[i];
            }
        }

        else {
            if (field[i] == -1) {
                cout << " " << "*";
            }

            else {
                cout << " " << field[i];
            }
        }
    }
}

int32_t main() {
    int x, y;
    cin >> x;
    cin >> y;

    vector<int> arr(x * y, 0) ;

    int n;
    cin >> n;

    solve(arr, x, y, n);

    return 0;
}