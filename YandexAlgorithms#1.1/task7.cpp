#include <iostream>

using namespace std;

void solveG(int n, int k, int m) {
    int details = 0;

    int quantity = k / m;
    int remains = k % m;

    if (remains < k) {
        while (n - k >= 0) {
            n = n - k + remains;
            details += quantity;
        }
    }

    cout << details << endl;
}

int main() {
    int n, k, m;
    cin >> n;
    cin >> k;
    cin >> m;

    solveG(n, k, m);

    return 0;
}
