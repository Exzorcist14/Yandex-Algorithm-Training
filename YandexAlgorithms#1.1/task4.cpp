#include <iostream>

using namespace std;

bool isInteger(float x) {
    return x == int(x);
}

int main() {
    float a;
    cin >> a;

    float  b;
    cin >> b;

    float  c;
    cin >> c;

    float x;

    if (c >= 0) {
        if (a != 0) {
            x = (c * c - b) / a;

            if (((a*x + b) >= 0) && isInteger(x)) {
                cout << x << endl;
            }

            else {
                cout << "NO SOLUTION" << endl;
            }
        }

        else if ((c*c - b) == 0) {
            cout << "MANY SOLUTIONS" << endl;
        }

        else {
            cout << "NO SOLUTION" << endl;
        }
    }

    else {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
};
