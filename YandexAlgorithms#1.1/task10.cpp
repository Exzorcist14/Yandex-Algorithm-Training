#include <bits/stdc++.h>

using namespace std;

bool isMatrixZero(vector<vector<double>> AB) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (AB[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

/*
Для упрощения приведения к ступенчатому виду, предполагается, что все вычитания будут производиться из первой строки.
Поскольку возможно ситуация, когда во второй строке слева направо ненулевой элемент встречается раньше, чем в первой,
то следует поменять их местами. Следующие две функции обеспечивают это.
*/

bool isNecessarySwitchPlaces(vector<vector<double>> AB) {
    if (AB[0][0] == 0) {
        if (AB[1][0] != 0) {
            return true;
        }

        else if (AB[0][1] == 0) {
            if (AB[1][1] != 0) {
                return true;
            }

            else if (AB[0][2] == 0) {
                if (AB[1][2] != 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

vector<vector<double>> switchPlaces(vector<vector<double>> AB) {
    vector<double> temp(3);
    for (int i = 0; i < 3; i++) {
        temp[i] = AB[0][i];
    }

    for (int i = 0; i < 3; i++) {
        AB[0][i] = AB[1][i];
        AB[1][i] = temp[i];
    }

    return AB;
}

//Ищет первый ненулевой элемент в первой строке
int findIndFirstNonZeroElement(vector<vector<double>> AB) {
    for (int i = 0; i < 3; i++) {
        if (AB[0][i] != 0) {
            return i;
        }
    }
}

vector<vector<double>> leadToStepwise(vector<vector<double>> AB) {
    if (isNecessarySwitchPlaces(AB)) {
        AB = switchPlaces(AB);
    }

    int indFirstNonZeroElement = findIndFirstNonZeroElement(AB);

    double firstNonZero = AB[0][indFirstNonZeroElement];

    if (AB[1][indFirstNonZeroElement] != 0) {
        double mult = AB[1][indFirstNonZeroElement];

        for (int i = 0; i < 3; i++) {
            AB[1][i] -= AB[0][i] * mult / firstNonZero;
        }
    }

    return AB;
}

bool isSecondRowNull(vector<vector<double>> AB) {
    return ((AB[1][0] * AB[1][0]) + (AB[1][1] * AB[1][1]) + (AB[1][2] * AB[1][2])) == 0;
}

bool areEqualRangs(vector<vector<double>> AB) {
    if (isSecondRowNull(AB)) {
        if (AB[0][0] != 0 || AB[0][1] != 0 || AB[0][2] == 0) {
            return true;
        }
    } else if (AB[1][1] != 0 || AB[1][2] == 0) {
        return true;
    }

    return false;
}

void solve(vector<vector<double>> AB) {
    if (isMatrixZero(AB)) {
        cout << 5;

        return;
    } else {
        AB = leadToStepwise(AB);

        if (!areEqualRangs(AB)) {
            cout << 0;

            return;
        } else if (!isSecondRowNull(AB)) {
            double y = AB[1][2] / AB[1][1];
            double x = (AB[0][2] - y * AB[0][1]) / AB[0][0];

            cout << 2 << " " << fixed << setprecision(5) << x << " " << y << "\n";

            return;
        } else if (AB[0][0] != 0 && AB[0][1] != 0) {
            double k = -AB[0][0]/AB[0][1];
            double b = AB[0][2]/AB[0][1];

            cout << 1 << " " << fixed << setprecision(5) << k << " " << b << "\n";

            return;
        } else if (AB[0][0] != 0) {
            cout << 3 << " " << fixed << setprecision(5) << AB[0][2] / AB[0][0];
        } else {
            cout << 4 << " " << fixed << setprecision(5) << AB[0][2] / AB[0][1];
        }
    }
}

int main() {
    vector<vector<double>> AB(2);
    for (int i = 0; i < 2; i++) {
        AB[i] = vector<double>(3);
    }

    cin >> AB[0][0];
    cin >> AB[0][1];
    cin >> AB[1][0];
    cin >> AB[1][1];
    cin >> AB[0][2];
    cin >> AB[1][2];

    solve(AB);

    return 0;
}