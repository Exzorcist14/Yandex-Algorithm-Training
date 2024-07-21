#include <iostream>
#include <string>

using namespace std;

void format(string* s) {
    string newS = "";

    for (int i = 0; i < s->length(); i++) {
        if (((*s)[i] != '+') && (((*s)[i] != '-') && ((*s)[i] != '(') && ((*s)[i] != ')'))) {
            newS += (*s)[i];
        }
    }

    if (newS.length() < 11) {
        newS = "7495" + newS;
    }

    if (newS[0] == '8') {
        newS.erase(0, 1);
        newS = "7" + newS;
    }

    *s = newS;
}

int main() {
    string search;
    cin >> search;

    format(&search);

    string contacts[3];

    for (int i = 0; i < 3; i++) {
        cin >> contacts[i];
        format(&contacts[i]);

        if (search == contacts[i]) {
            cout << "YES" << endl;
        }

        else {
            cout << "NO" << endl;
        }
    }

    return 0;
};
