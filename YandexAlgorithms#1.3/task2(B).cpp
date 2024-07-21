#include <bits/stdc++.h>

#define int long long

using namespace std;

/*
Конструкция if-else позволяет добиться незначительной оптимизации. Хотя в худшем случае не важно, какое
множество больше (N*M итераций = M*N итераций, где N и M - длины множеств), вероятность найти элемент из
множества большего размера в меньшем больше, и поиск будет прекращаться раньше.
*/

void solve(set<int> numbers1, set<int> numbers2) {
    if (numbers1.size() <= numbers2.size()) {
        for (int element : numbers2) {
            if (numbers1.contains(element)) {
                cout << element << " ";
            }
        }
    } else {
        for (int element : numbers1) {
            if (numbers2.contains(element)) {
                cout << element << " ";
            }
        }
    }
}

int32_t main() {
    set<int> numbers1;
    set<int> numbers2;

    ifstream fin("input.txt");
    string tempString;

    getline(fin, tempString);
    istringstream iss1(tempString);

    int tempNumber;
    while (iss1 >> tempNumber) {
        numbers1.insert(tempNumber);
    }

    getline(fin, tempString);
    istringstream iss2(tempString);

    while (iss2 >> tempNumber) {
        numbers2.insert(tempNumber);
    }

    solve(numbers1, numbers2);

    return 0;
}