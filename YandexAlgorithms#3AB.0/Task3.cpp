#include <bits/stdc++.h>
using namespace std;

bool inStock(const int& sticker, const int& p) {
    return sticker >= p;
}

int rightBinSearch(vector<int>& diego, int& p) {
    int l = 0;
    int r = diego.size() - 1;
    int mid;

    while (l != r) {
        mid = (l + r + 1) / 2;

        if (!inStock(diego[mid], p)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return (!inStock(diego[r], p) ? r + 1 : 0);
}

void solve() {
    ifstream fin("input.txt");

    //Считываем информацию о Диего
    int N;
    fin >> N;

    //Промежуточное упорядоченное множество
    set<int> diegoSet;
    int temp;

    for (int i = 0; i < N; ++i) {
        fin >> temp;
        diegoSet.insert(temp);
    }

    //Вектор, составленные на множестве, с которым будет вестись работа
    vector<int> diego;
    for (auto& sticker : diegoSet) {
        diego.push_back(sticker);
    }

    //Считываем информацию о коллекционерах
    int K;
    fin >> K;

    vector<int> collectors(K);
    for (int i = 0; i < K; ++i) {
        fin >> collectors[i];
    }

    /*
     * Для каждого коллекционера правым бинарным поиском найдём последнюю наклейку Диего, что нет
     * у него. Тогда ответом для него будет индекс этой найлейки + 1
     */

    vector<int> answers(K);

    for (int i = 0; i < K; i++) {
        answers[i] = rightBinSearch(diego, collectors[i]);
    }

    for (auto& ans : answers) {
        cout << ans << "\n";
    }
}

int main() {
    solve();
    return 0;
}