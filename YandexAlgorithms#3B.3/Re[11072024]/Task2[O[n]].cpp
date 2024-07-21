#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N, k;
    fin >> N >> k;

    vector<int> window(min(N, k));
    window[0] = 1;

    int sum = window[0]; //Подсчитаем сразу сумму в окне
    for (int i = 1; i < min(N, k); ++i) {
        for (int prev = 0; prev < i; ++prev) {
            if (i - prev >= 0) {
                window[i] += window[prev]; //Подсчитываем количество способом прийти в i-ю ячейку окна
            }
        }

        sum += window[i];
    }

    int newValue;
    for (int i = min(N, k); i < N; ++i) {
        newValue = sum;

        //Перерасчёт суммы в окне
        sum -= window[i % k];
        window[i % k] = newValue;
        sum += window[i % k];
    }

    cout << window[(N - 1) % k] << "\n";
}

int main() {
    solve();
    return 0;
}