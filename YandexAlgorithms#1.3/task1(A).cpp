#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(unordered_set<int> numbers) {
    int count = 0;
    for (int element : numbers) {
        count++;
    }

    cout << count << "\n";
}

int32_t main() {
    ifstream fin("input.txt");

    unordered_set<int> numbers;
    int temp;
    while (fin >> temp) {
        numbers.insert(temp);
    }

    solve(numbers);

    return 0;
}
