#include <bits/stdc++.h>

#define int long long

using namespace std;

unordered_set<int> findSetOfNumbers(int N) {
    unordered_set<int> numbers;

    while (N > 0) {
        numbers.insert(N % 10);
        N /= 10;
    }

    return numbers;
}

void solve(int x, int y, int z, int N) {
    int counter = 0;

    unordered_set<int> numbers = findSetOfNumbers(N);

    for (int element : numbers) {
        if (element != x && element != y && element != z) {
            counter++;
        }
    }

    cout << counter << "\n";
}

int32_t main() {
    int x, y, z;
    cin >> x >> y >> z;

    int N;
    cin >> N;

    solve(x, y, z, N);

    return 0;
}