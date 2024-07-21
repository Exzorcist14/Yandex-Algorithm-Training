#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(vector<int> arr) {
    int indPositive = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            indPositive = i;
            break;
        }
    }

    if (indPositive == -1) {
        int tempId1 = 0;
        for (int i = 1; i < 3; i++) {
            if (arr[i] > arr[tempId1]) {
                tempId1 = i;
            }
        }
        int minAbsNegative1 = arr[tempId1];

        int tempId2 = (tempId1 + 1) % 3;
        for (int i = 0; i < 3; i++) {
            if (arr[i] > arr[tempId2] && i != tempId1) {
                tempId2 = i;
            }
        }
        int minAbsNegative2 = arr[tempId2];

        int tempId3 = 3 - tempId1 - tempId2;
        for (int i = 0; i < 3; i++) {
            if (arr[i] > arr[tempId2] && i != tempId1 && i != tempId2) {
                tempId2 = i;
            }
        }
        int minAbsNegative3 = arr[tempId3];

        for (int i = 3; i < arr.size(); i++) {
            if (arr[i] <= 0) {
                if (arr[i] > minAbsNegative1) {
                    minAbsNegative3 = minAbsNegative2;
                    minAbsNegative2 = minAbsNegative1;
                    minAbsNegative1 = arr[i];
                }

                else if (arr[i] > minAbsNegative2) {
                    minAbsNegative3 = minAbsNegative2;
                    minAbsNegative2 = arr[i];
                }

                else if (arr[i] > minAbsNegative3) {
                    minAbsNegative3 = arr[i];
                }
            }

            else {
                indPositive = i;
                break;
            }
        }

        if (indPositive == -1) {
            cout << minAbsNegative1 << " " << minAbsNegative2 << " " << minAbsNegative3 << endl;
        }
    }

    if (indPositive != -1) {
        int maxPositive1 = -1;

        int maxPositive2 = -1;
        int maxPositive3 = -1;

        int maxAbsNegative2 = 1;
        int maxAbsNegative3 = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                if (arr[i] > maxPositive1) {
                    maxPositive3 = maxPositive2;
                    maxPositive2 = maxPositive1;
                    maxPositive1 = arr[i];
                }

                else if (arr[i] > maxPositive2) {
                    maxPositive3 = maxPositive2;
                    maxPositive2 = arr[i];
                }

                else if (arr[i] > maxPositive3) {
                    maxPositive3 = arr[i];
                }
            }

            else {
                if (arr[i] < maxAbsNegative2) {
                    maxAbsNegative3 = maxAbsNegative2;
                    maxAbsNegative2 = arr[i];
                }

                else if (arr[i] < maxAbsNegative3) {
                    maxAbsNegative3 = arr[i];
                }
            }
        }

        if (maxPositive2 * maxPositive3 >= 0) {
            if (maxAbsNegative2 <= 0 && maxAbsNegative3 <= 0) {
                if (maxPositive1 * maxPositive2 * maxPositive3 >= maxPositive1 * maxAbsNegative2 * maxAbsNegative3) {
                    cout << maxPositive1 << " " << maxPositive2 << " " << maxPositive3 << endl;
                }

                else {
                    cout << maxPositive1 << " " << maxAbsNegative2 << " " << maxAbsNegative3 << endl;
                }
            }

            else {
                cout << maxPositive1 << " " << maxPositive2 << " " << maxPositive3 << endl;
            }
        }

        else if (maxAbsNegative2 <= 0 && maxAbsNegative3 <= 0) {
            cout << maxPositive1 << " " << maxAbsNegative2 << " " << maxAbsNegative3 << endl;
        }

        else {
            cout << maxPositive1 << " " << maxPositive2 << " " << maxAbsNegative2 << endl;
        }
    }
}

int32_t main() {
    ifstream input("input.txt");

    vector<int> source;
    int temp;

    while (input >> temp) {
        source.push_back(temp);
    }

    solve(source);

    return 0;
}