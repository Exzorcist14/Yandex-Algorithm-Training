#include <iostream>
#include <string>

using namespace std;

int main() {
    int tRoom;
    cin >> tRoom;

    int tCond;
    cin >> tCond;

    string command;

    cin >> command;

    int ans = tRoom;

    if (command == "auto") {
        ans = tCond;
    }

    else if (command == "freeze") {
        if (tCond < tRoom) {
            ans = tCond;
        }
    }

    else if (command == "heat") {
        if (tCond > tRoom) {
            ans = tCond;
        }
    }

    cout << ans << endl;

    return 0;
};
