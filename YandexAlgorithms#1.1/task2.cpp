#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int max = x, min = x, sum = x;

    for (int i = 0; i < 2; i++) {
        cin >> x;

        if (x > max) {
            max = x;
        }

        else if (x < min) {
            min = x;
        }

        sum += x;
    }

    if (((sum - max - min) + min) > max) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }

    return 0;
};
