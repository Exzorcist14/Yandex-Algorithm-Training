#include <iostream>
#include <vector>

using namespace std;

void solveС() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int search;
    cin >> search;

    int currDiff;
    int minDiff = abs(numbers[0] - search);
    int ans = numbers[0];

    for (int i = 1; i < n; i++) {
        currDiff = abs(numbers[i] - search);
        if (currDiff < minDiff) {
            ans = numbers[i];
            minDiff = currDiff;
        }
    }

    cout << ans << endl;
}

int main() {
    solveС();

    return 0;
}

