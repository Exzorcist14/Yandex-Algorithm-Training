#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void solveD(vector<int> input) {
    int ans = 0;

    bool grew = input[1] > input[0];
    for (int i = 2; i < input.size(); i++) {
        if (input[i] < input[i-1]) {
            if (grew) {
                ans += 1;
            }

            grew = false;
        }

        else {
            grew = true;
        }
    }

    cout << ans << endl;
}

int main() {
    vector<int> input;
    ifstream fin("input.txt");

    int n;

    while (fin >> n) {
        input.push_back(n);
    }

    fin.close();

    solveD(input);

    return 0;
}

