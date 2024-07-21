#include <bits/stdc++.h>

#define int long long

using namespace std;

void playFirstOption(vector<int>& seq, int& maxH,
                     vector<pair<int, pair<int, int>>>& totalLifts,
                     vector<pair<int, int>>& morningLifts) {

    /*
        Стратегия:
            Кормим всеми ягодами, которые суммарно поднимут нашу улитку вверх (за день и ночь),
            а затем среди ягод, которые в конечном счете не поднимут нас выше ищем такую,
            которая сможет поднять нас как можно выше по утру, чтобы совершить "последний рывок".

            Так мы достигаем максимума этой стратегии.

            Порядок остальных ягод нас уже не интересует.
    */

    int h = 0;
    int indOfMaxLift;

    //Суммарно поднимаемся
    for (auto& lift : totalLifts) {
        h += lift.first;
        seq.push_back(lift.second.second);
    }

    maxH = h;

    //Ищем ягоду "последнего рывка"
    for (auto& lift : morningLifts) {
        if (h + lift.first > maxH) {
            maxH = h + lift.first;
            indOfMaxLift = lift.second;
        }
    }

    //Последний рывок
    seq.push_back(indOfMaxLift);

    //Порядок остальных ягод нас уже не интересует, но они идут после "рывка".
    for (auto& lift : morningLifts) {
        if (lift.second != indOfMaxLift) {
            seq.push_back(lift.second);
        }
    }
}

void playSecondOption(vector<int>& seq, int& maxH,
                      vector<pair<int, pair<int, int>>>& totalLifts,
                      vector<pair<int, int>>& morningLifts) {

    /*
        Стратегия:
            Среди суммарно поднимающих ягод найдём такую, снижение вечером которой максимально,
            то есть найдём минимальное значение выражения:

                b = (A - (A - B))

                Эквивалент на языке наших структур:
                lowering = (lift.second.first - lift.first)

            Скормим все ягоды, которые суммарно поднимают улитку, кроме той,
            снижение которой максимально. Её скармливаем последней из числа суммарно поднимающих.

            Так мы достигаем максимума этой стратегии.

            Порядок остальных ягод нас уже не интересует.
    */

    int h = 0;
    int indOfMaxLowering;
    int maxLowering = -1000000001;

    //Ищем ягоду из суммарно поднимающих с наибольшим снижением
    for (auto& lift : totalLifts) {
        if (lift.second.first - lift.first > maxLowering)  {
            maxLowering = lift.second.first - lift.first;
            indOfMaxLowering = lift.second.second;
        }
    }

    //Кормим такими ягодами, в конце добавляя найденную
    for (auto& lift : totalLifts) {
        if (lift.second.second != indOfMaxLowering) {
            h += lift.first;
            seq.push_back(lift.second.second);
        } else {
            h += lift.second.first;
        }
    }

    seq.push_back(indOfMaxLowering);

    //Порядок остальных ягод нас уже не важен
    for (auto& lift : morningLifts) {
        seq.push_back(lift.second);
    }

    maxH = h;
}

void displayBest(int& maxH1, int& maxH2, vector<int>& seq1, vector<int>& seq2) {
    if (maxH1 > maxH2) {
        cout << maxH1 << endl;
        for (int i = 0; i < seq1.size(); i++) {
            cout << seq1[i] << " ";
        }
    } else {
        cout << maxH2 << endl;
        for (int i = 0; i < seq2.size(); i++) {
            cout << seq2[i] << " ";
        }
    }

    cout << "\n";
}

void solve(int n, vector<pair<int, pair<int, int>>>& totalLifts, vector<pair<int, int>>& morningLifts) {
    /*
        Развитие событий можно поделить на два противоположных варианта,
        в совокупности описывающих достижение наибольшей высоты
    */

    vector<int> seq1;
    int maxH1 = -1000000001;

    playFirstOption(seq1, maxH1, totalLifts, morningLifts);

    vector<int> seq2;
    int maxH2 = -1000000001;

    playSecondOption(seq2, maxH2, totalLifts, morningLifts);

    //Отображаем результат лучшего варианта развития событий
    displayBest(maxH1, maxH2, seq1, seq2);
}

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> totalLifts; //Содержит ягоды, которые суммарно поднимают нас
    vector<pair<int, int>> morningLifts; //Содержит остальные ягоды

    int x, y;

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;

        if (x - y > 0) {
            totalLifts.push_back({x - y, {x, i}});
        } else {
            morningLifts.push_back({x, i});
        }
    }

    solve(n, totalLifts, morningLifts);

    return 0;
}
