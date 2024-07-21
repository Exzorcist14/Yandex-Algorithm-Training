#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    ifstream fin("input.txt");
    int k;
    string str;
    fin >> k >> str;

    //Конструируем словарь символ - отрезки {начало, конец}
    unordered_map<char, vector<pair<int, int>>> charSegments;
    int begin = 0;
    int end = 1;

    while (end != str.size()) {
        if (str[end] == str[end - 1]) {
            ++end;
        } else {
            charSegments[str[begin]].emplace_back(begin, end - 1);
            begin = end;
            end = end + 1;
        }
    }

    charSegments[str[begin]].emplace_back(begin, end - 1);

    //Будем использовать идею скользящего окна
    int first, last;
    int i, j;
    int reserve;
    int diff;

    int maxL = -1;

    for (auto& [s, o] : charSegments) {
        first = 0; //Указывает на первый отрезок для окна
        last = 0; //Указывает на последний отрезок для окна

        i = o[first].first; //Указывает на индекс начала отрезка
        j = o[first].second; //Указывает на индекс конца отрезка

        reserve = k; //Указывает на доступный резерв

        /*
         * Пример:
         * { [0; 1], [5, 8] } - начальный i = 0, j = 1
         */

        //Рассчитаем первое окно
        while (reserve != 0) { //Пока можем менять буквы

            if (last != o.size() - 1 &&
                (j + 1) == o[last + 1].first) {

                j = o[last + 1].second; //скачок
                last++;
            } else {
                reserve--;
                j++;
            }
        }

        //Когда мы больше не можем менять буквы, могло оказаться, что следующая клетка наша
        if (last != o.size() - 1 &&
            j + 1 == o[last + 1].first) {

            j = o[last + 1].second;
            last++;
        }

        if (j >= str.size()) { //Если вылезли за исходную строку
            diff = (j - str.size() + 1);

            if (i - diff >= 0) { //Начало сдвигается влево на то значение, насколько вылезли за строку
                i -= (j - str.size() + 1);
            } else { //Начало точно не меньше первого символа строки
                i = 0;
            }

            j = str.size() - 1; //Конец ограничивается последним символов строки
        }

        maxL = max(j - i + 1, maxL);

        /*
         * Каждое следующее окно будет начинаться со следующего после first отрезка,
         * поскольку начинать в уже рассмотренном отрезке или не в нашей букве бессмысленно
         */

        //Двигаем окно
        while (first != o.size() - 1) {

            //Обновление данных об окне
            first++;
            i = o[first].first;
            if (j < o[first].second) {
                j = o[first].second;
                last = first;
                reserve = k;
            } else {
                reserve = o[first].first - o[first - 1].second - 1;
            }

            //Расширяем окно по возможности
            while (reserve != 0) { //Пока можем менять буквы

                if (last != o.size() - 1 &&
                    (j + 1) == o[last + 1].first) { //j >= o[last + 1].first && j <= o[last + 1].second

                    j = o[last + 1].second; //скачок
                    last++;
                } else {
                    reserve--;
                    j++;
                }
            }

            //Когда мы больше не можем менять буквы, могло оказаться, что следующая клетка наша
            if (last != o.size() - 1 &&
                j + 1 == o[last + 1].first) {

                j = o[last + 1].second;
                last++;
            }

            if (j >= str.size()) { //Если вылезли за исходную строку
                diff = (j - str.size() + 1);

                if (i - diff >= 0) { //Начало сдвигается влево на то значение, насколько вылезли за строку
                    i -= (j - str.size() + 1);
                } else { //Начало точно не меньше первого символа строки
                    i = 0;
                }

                j = str.size() - 1; //Конец ограничивается последним символов строки
            }

            maxL = max(j - i + 1, maxL);
        }
    }

    cout << maxL << "\n";
}

int32_t main() {
    solve();
    return 0;
}
