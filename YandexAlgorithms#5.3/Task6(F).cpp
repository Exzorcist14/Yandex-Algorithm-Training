#include <bits/stdc++.h>

using namespace std;

string tryToShorten(const string& word, const unordered_set<string>& dictionary) {
    string currPrefix;

    for (int i = 0; i < word.size(); i++) {
        currPrefix += word[i];

        if (dictionary.contains(currPrefix)) {
            return currPrefix;
        }
    }

    return currPrefix;
}

void solve() {
    unordered_set<string> dictionary;
    vector<string> text;

    string line;
    getline(cin, line);
    istringstream iss1(line);

    string dictionaryElement;
    while (iss1 >> dictionaryElement) {
        dictionary.insert(dictionaryElement);
    }

    getline(cin, line);
    istringstream iss2(line);

    string word;
    while (iss2 >> word) {
        text.push_back(tryToShorten(word, dictionary));
    }

    for (auto& elem : text) {
        if (!elem.empty()) {
            cout << elem << " ";
        }
    }
    cout << "\n";
}

int main() {
    solve();

    return 0;
}
