#include <iostream>

using namespace std;

void solveI(int A, int B, int C, int D, int E) {
    int side[]{A, B, C};
    bool flag = false;

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if ((side[i] <= D) && (side[j] <= E) || (side[j] <= D) && (side[i] <= E)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            break;
        }


    }

    if (flag) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
}

int main() {
    int A, B, C, D, E;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    cin >> E;

    solveI(A, B, C, D, E);

    return 0;
}
