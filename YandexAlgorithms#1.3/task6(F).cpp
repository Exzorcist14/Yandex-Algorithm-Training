#include <bits/stdc++.h>

using namespace std;

void solve(string firstG, string secondG) {
    unordered_multiset<string> firstPairs;

    for (int i = 0; i < firstG.size() - 1; i++) {
        firstPairs.insert(string(1, firstG[i]) + firstG[i+1]);
    }

    unordered_set<string> secondPairs;

    for (int i = 0; i < secondG.size() - 1; i++) {
        secondPairs.insert(string(1, secondG[i]) + secondG[i+1]);
    }

    int counter = 0;

    for (string element : firstPairs) {
        if (secondPairs.contains(element)) {
            counter++;
        }
    }

    cout << counter << "\n";
}

int main() {
    string firstG, secondG;

    getline(cin, firstG);
    getline(cin, secondG);

    solve(firstG, secondG);

    return 0;
}