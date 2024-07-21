#include <bits/stdc++.h>

using namespace std;

void solve(int n, unordered_multiset<string> languages) {
    unordered_set<string> wellKnownLanguages;
    unordered_set<string> uniqueLanguages;

    for (string element : languages) {
        if (languages.count(element) == n) {
            wellKnownLanguages.insert(element);
        }

        uniqueLanguages.insert(element);
    }

    cout << wellKnownLanguages.size() << "\n";
    for (string element : wellKnownLanguages) {
        cout << element << "\n";
    }

    cout << uniqueLanguages.size() << "\n";
    for (string element : uniqueLanguages) {
        cout << element << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    unordered_multiset<string> languages;

    int mI;
    string tempStr;

    for (int i = 0; i < n; i++) {
        cin >> mI;
        cin.ignore(1);

        for (int j = 0; j < mI; j++) {
            getline(cin, tempStr);
            languages.insert(tempStr);
        }
    }

    solve(n, languages);

    return 0;
}
