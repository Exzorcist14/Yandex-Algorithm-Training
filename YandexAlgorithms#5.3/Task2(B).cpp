#include <bits/stdc++.h>

using namespace std;

void makeAlphabet(const string& str, unordered_map<char, int>& alphabet) {
    for (int i = 0; i < str.size(); i++) {
        alphabet[str[i]]++;
    }
}

void solve(const string& firstString, const string& secondString) {
    unordered_map<char, int> alphabet1;
    makeAlphabet(firstString, alphabet1);

    unordered_map<char, int> alphabet2;
    makeAlphabet(secondString, alphabet2);

    if (alphabet1 == alphabet2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    string firstString;
    cin >> firstString;

    string secondString;
    cin >> secondString;

    solve(firstString, secondString);

    return 0;
}
