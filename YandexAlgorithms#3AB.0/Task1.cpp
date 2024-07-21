#include <bits/stdc++.h>

using namespace std;

void solve() {
    ifstream fin("input.txt");

    map<char, int> counters; //словарь символ - его количество
    char symb;
    int maxH = -1;

    while (fin >> symb) {
        if (symb != ' ') {
            counters[symb]++;
        }
        maxH = max(counters[symb], maxH);
    }

    //Гистограмма
    vector<vector<char>> histogram;
    vector<char> line(counters.size(), ' ');
    for (int i = 0; i < maxH; i++) {
        histogram.push_back(line);
    }

    //Последняя строка - легенда гистограммы (символы)
    int ind = 0;
    for (auto& [s, c] : counters) {
        line[ind] = s;
        ++ind;
    }
    histogram.push_back(line);

    //Отрисовываем гистограмму
    for (int col = 0; col < counters.size(); col++) {
        for (int row = maxH - 1; row >= maxH - counters[histogram[maxH][col]]; --row) {
            histogram[row][col] = '#';
        }
    }

    //Выводим гистограмму
    for (int i = 0; i < histogram.size(); ++i) {
        for (int j = 0; j < histogram[i].size(); ++j) {
            cout << histogram[i][j];
        }
        cout << "\n";
    }
}

int32_t main() {
    solve();
    return 0;
}
