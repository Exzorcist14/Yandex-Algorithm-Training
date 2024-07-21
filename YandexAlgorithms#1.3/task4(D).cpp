#include <bits/stdc++.h>

using namespace std;

void solve(unordered_set<string> text) {
    cout << text.size() << "\n";
}

int main() {
    unordered_set<string> text;

    ifstream fin("input.txt");
    string temp;
    while (fin >> temp) {
        text.insert(temp);
    }

    solve(text);

    return 0;
}