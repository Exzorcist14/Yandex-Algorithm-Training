#include <bits/stdc++.h>

#define int long long

using namespace std;

void solveG(vector<int> a) {
    int positiveMaxmult1 = 0;
    int positiveMaxmult2 = 0;

    int negativeMinMult1 = 0;
    int negativeMinMult2 = 0;

    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] >= positiveMaxmult1) {
            positiveMaxmult2 = positiveMaxmult1;
            positiveMaxmult1 = a[i];
        } else if (a[i] > positiveMaxmult2) {
            positiveMaxmult2 = a[i];
        } else if (a[i] <= negativeMinMult1) {
            negativeMinMult2 = negativeMinMult1;
            negativeMinMult1 = a[i];
        } else if (a[i] < negativeMinMult2) {
            negativeMinMult2 = a[i];
        }
    }

    if (positiveMaxmult1 * positiveMaxmult2 > negativeMinMult1 * negativeMinMult2) {
        cout << positiveMaxmult2 << " " << positiveMaxmult1 << endl;
    } else if (n > 2) {
        cout << negativeMinMult1 << " " << negativeMinMult2 << endl;
    } else {
        cout << min(a[1], a[0]) << " " << max(a[0], a[1]) << endl;

    }

}

int32_t main() {
    vector<int> input;
    ifstream fin("input.txt");

    int n;
    while (fin >> n) {
        input.push_back(n);
    }

    fin.close();

    solveG(input);

    return 0;
}

