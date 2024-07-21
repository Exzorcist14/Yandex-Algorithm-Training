#include <bits/stdc++.h>

#define int long long

using namespace std;

//Ищет сильнейшего персонажа в незапрещённой части таблицы, а также строку и столбец с ним.
vector<int> findAvailableMax(int forbiddenRow, int forbiddenColumn,
                             const vector<vector<int>>& table, int n, int m) {

    int availableMax = -1;
    int row;
    int column;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i != forbiddenRow && j != forbiddenColumn) {

                if (table[i][j] > availableMax) {
                    availableMax = table[i][j];
                    row = i;
                    column = j;
                }
            }
        }
    }

    vector<int> result = {availableMax, row, column};

    return result;
}

//Ищет сильнейшего персонажа, который может получить противник, если сначала вычеркнуть строку
vector<int> forbidRow(const vector<int>& lastAvailableMax, const vector<vector<int>>& table, int n, int m) {
    //Теперь вычеркнем столбец с числом, содержащий максимум в оставшейся части таблицы
    vector<int> currentAvailableMax = findAvailableMax(lastAvailableMax[1], -1, table, n, m);

    //Получившийся сильнейший персонаж противника
    vector<int> remainingAvailableMax = findAvailableMax(lastAvailableMax[1], currentAvailableMax[2], table, n, m);

    //Информация о выборе противника, а также вычеркнутой строке и столбцу, которые привели к нему
    vector<int> result = {remainingAvailableMax[0], lastAvailableMax[1] + 1, currentAvailableMax[2] + 1};

    return result;
}

//Ищет сильнейшего персонажа, который может получить противник, если сначала вычеркнуть столбец
vector<int> forbidColumn(const vector<int>& lastAvailableMax, const vector<vector<int>>& table, int n, int m) {
    //Теперь вычеркнем строку с числом, содержащую максимум в оставшейся части таблицы
    vector<int> currentAvailableMax = findAvailableMax(-1, lastAvailableMax[2], table, n, m);

    //Получившийся сильнейший персонаж противника
    vector<int> remainingAvailableMax = findAvailableMax(currentAvailableMax[1], lastAvailableMax[2], table, n, m);

    //Информация о выборе противника, а также вычеркнутой строке и столбцу, которые привели к нему
    vector<int> result = {remainingAvailableMax[0], currentAvailableMax[1] + 1, lastAvailableMax[2] + 1};

    return result;
}


void solve(const vector<vector<int>>& table, int n, int m) {
    /*
        Найдем сильнейшего персонажа во всей игре.
    */

    vector<int> availableMax = findAvailableMax(-1, -1, table, n, m);

    /*
        Его можно забанить двумя способами: вычеркиванием столбца и вычеркиванием строки.
        Попробуем разыграть оба способа.
    */

    vector<int> firstResult = forbidRow(availableMax, table, n, m);
    vector<int> secondResult = forbidColumn(availableMax, table, n, m);

    /*
        Сравним, какая симуляция дала лучший для Михаила результат.
        Таким рузультатом является более слабый персонаж Константина - нашего противника.
    */

    if (firstResult[0] <= secondResult[0]) {
        cout << firstResult[1] << " " << firstResult[2] << "\n";
    } else {
        cout << secondResult[1] << " " << secondResult[2] << "\n";
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n);
    vector<int> temp(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp[j];
        }
        table[i] = temp;
    }

    solve(table, n, m);

    return 0;
}
