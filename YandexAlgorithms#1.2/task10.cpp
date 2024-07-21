#include <bits/stdc++.h>

using namespace std;

void solve(vector<double> seq) {
    double left = 30;
    double right = 4000;

    double mid;

    for (int i = 1; i < seq.size(); i++) {
        mid = (abs(seq[i-1])  + abs(seq[i])) / 2;

        if (abs(seq[i]) > abs(seq[i-1])) {
            seq[i] > 0 ? right = min(right, mid) : left = max(left, mid);
        }

        else if (abs(seq[i]) < abs(seq[i-1])) {
            seq[i] > 0 ? left = max(left, mid) : right = min(right, mid);
        }
    }

    cout << fixed << left << " " << fixed << right << "\n"; //Вывод чисел с точностью не хуже 10^(-6)
}

int main() {
    int n;
    cin >> n;

    vector<double> seq(n);
    string buff;

    cin >> seq[0];

    for (int i = 1; i < n; i++) {
        cin >> seq[i];
        cin >> buff;

        if (buff[0] == 'c') { //В качестве указания на "близость" используется знак числа, поскольку минимальная частота по условию 30 > 0
            seq[i] = -seq[i];
        }
    }

    solve(seq);

    return 0;
}