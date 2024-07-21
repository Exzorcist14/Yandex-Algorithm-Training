#include <iostream>

using namespace std;

void solveB() {
    bool wasIncrease = false;
    bool wasEquality = false;
    bool wasDecrease = false;

    int past;
    cin >> past;

    if (past != -2000000000) {
        int curr;
        cin >> curr;

        if (curr != -2000000000) {
            while (curr != -2000000000) {
                if (curr > past) {
                    wasIncrease = true;
                }

                else if (curr == past) {
                    wasEquality = true;
                }

                else {
                    wasDecrease = true;
                }

                past = curr;
                cin >> curr;
            }

            if (wasIncrease and wasDecrease) {
                cout << "RANDOM" << endl;
            }

            else if (wasIncrease and wasEquality) {
                cout << "WEAKLY ASCENDING" << endl;
            }

            else if (wasEquality and wasDecrease) {
                cout << "WEAKLY DESCENDING" << endl;
            }

            else if (wasIncrease) {
                cout << "ASCENDING" << endl;
            }

            else if (wasEquality) {
                cout << "CONSTANT" << endl;
            }

            else {
                cout << "DESCENDING" << endl;
            }
        }

        else {
            cout << "CONSTANT" << endl;
        }
    }

    else {
        cout << "RANDOM" << endl;
    }
}

int main() {
    solveB();

    return 0;
}

