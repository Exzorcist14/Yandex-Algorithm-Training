#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solveA(vector<int> input) {
    bool ans = true;

    for (int i = 1; i < input.size(); ++i) {
        if (input[i] <= input[i-1]) {
            ans = false;
            break;
        }
    }

    if (ans == true) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
}


int main() {
    vector<int> input;
    ifstream fin("input.txt");

    int n;

    while (fin >> n) {
        input.push_back(n);
    }

    fin.close();

    solveA(input);

    return 0;
}

