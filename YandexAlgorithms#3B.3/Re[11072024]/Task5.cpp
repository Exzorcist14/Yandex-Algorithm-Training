#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<int> pin(N);
    for (int i = 0; i < N; ++i) {
        fin >> pin[i];
    }

    sort(pin.begin(), pin.end());

    //dp[i] - минимальная длина ниточек с учётом того, что все гвоздики до i-ой и i-ая связаны хотя бы с одной
    vector<int> dp(N, INT_MAX);
    dp[1] = pin[1] - pin[0];

    for (int i = 2; i < N; ++i) {
        //Выбираем между вариантами:
        //1) i - 2 ниточки уже оптимально связаны, и можно связать i - 1 с i-ой. (-* *-*)
        //2) i - 1 ниточки уже оптимально связаны, связываем i - 1 с i-ой. (-*-*-*)
        //Эти варианты всецело описывают случай, когда все гвоздики будут в итоге связаны.
        dp[i] = min(dp[i - 2], dp[i - 1]) + pin[i] - pin[i - 1];
    }

    cout << dp[N - 1] << "\n";
}

int main() {
    solve();
    return 0;
}