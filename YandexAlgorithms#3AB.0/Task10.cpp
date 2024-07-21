#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    string word;
    fin >> word;

    map<char, long long> rep;
    for (int i = 0; i < word.size(); ++i) {
        rep[word[i]] += (word.size() - i) * (i + 1);
    }

    for (auto& [letter, count] : rep) {
        cout << letter << ": " << count << "\n";
    }
}

int main() {
    solve();
    return 0;
}
