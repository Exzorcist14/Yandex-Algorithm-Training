#include <iostream>

using namespace std;

int abs(int x) {
    if (x >= 0) {
        return x;
    }

    return -x;
}

void solveH(int a, int b, int n, int m) {
    int minFirstLineTime = n * (a + 1) - a;
    int maxFirstLineTime = n * (a + 1) + a;

    int minSecondLineTime = m * (b + 1) - b;
    int maxSecondLineTime = m * (b + 1) + b;

    if (maxFirstLineTime < minSecondLineTime || maxSecondLineTime < minFirstLineTime) {
        cout << -1 << endl;
    }

    else {
        if ((minFirstLineTime > minSecondLineTime)) {
            if (maxFirstLineTime < maxSecondLineTime) {
                cout << minFirstLineTime << " " << maxFirstLineTime << endl;
            }
            else {
                cout << minFirstLineTime << " " << maxSecondLineTime << endl;
            }
        }

        else {
            if (maxFirstLineTime < maxSecondLineTime) {
                cout << minSecondLineTime << " " << maxFirstLineTime << endl;
            }
            else {
                cout << minSecondLineTime << " " << maxSecondLineTime << endl;
            }
        }
    }

}

int main() {
    int a, b, n, m;
    cin >> a;
    cin >> b;
    cin >> n;
    cin >> m;

    solveH(a, b, n, m);

    return 0;
}
