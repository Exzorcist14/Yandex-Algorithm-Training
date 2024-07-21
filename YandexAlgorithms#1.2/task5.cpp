#include <bits/stdc++.h>
#include <vector>

using namespace std;

int findWinner(vector<int> arr) {
    int maxRange = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxRange) {
            maxRange = arr[i];
        }
    }

    return maxRange;
}

int findIndexSuitableRange(vector<int> arr) {
    int indexSuitableRange = -1;

    bool winnerPassed = false;
    int winnerRange = findWinner(arr);

    for (int i = 0; i < (arr.size() - 1); i++) {
        if ((arr[i] > arr[i+1]) && winnerPassed &&
           (arr[i] % 5 == 0) && (arr[i] % 10 != 0)) {

            if ((arr[i] > arr[indexSuitableRange]) || (indexSuitableRange == -1)) {
                indexSuitableRange = i;
            }
        }

        if (arr[i] == winnerRange) {
            winnerPassed = true;
        }
    }

    return indexSuitableRange;
}

int findPlace(vector<int> arr) {
    int indexRange = findIndexSuitableRange(arr);

    if (indexRange == -1) {
        return 0;
    }

    else {
        int place = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > arr[indexRange]) {
                place++;
            }
        }

        return place;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findPlace(arr) << "\n";

    return 0;
}