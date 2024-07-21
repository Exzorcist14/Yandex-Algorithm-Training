#include <bits/stdc++.h>

using namespace std;

/*
        ships = вектор строк, содержащих множества кораблей в строке с данным номером.
        ships[i] = множество кораблей в i-ой строке
        ship : ships[i] - корабль в i-строке. Представляет собой пару чисел, описывающих координату
*/

void solve(const vector<vector<pair<int, int>>>& ships, int N) {
    /*
        Нужно переставить корабли так, чтобы в каждой строке был ровно один корабль, причём сделать это
        за минимальное количество шагов.
            Под перемещением подразумевается вычисление количества шагов, необходимых для него,
            И изменение количества кораблей в каждой строке, не меняющее расположение самих кораблей.

        Инициализируем массив, отражающий количество кораблей в каждой строке.
            Изначально каждый i-ый элемент совпадает с размером i-го множества.
    */

    vector<int> currentNumberOfShipsInRow(N);
    for (int i = 0; i < N; i++) {
        currentNumberOfShipsInRow[i] = ships[i].size();
    }

    /*
        Воспользуемся идеей двух указателей для оптимального распределения кораблей по строкам.

        Указатель indEmpty указывает на текущую пустую строку, в которую нужно поставить корабль.
            Он увеличивается после абстрактного перемещения корабля в эту строку.

        Указатель indOverflow указывает на текущую заполненную более одним кораблём строку (переполненную),
        из которой можно абстрактно переместить корабль в строку с номером indEmpty.
            Он увеличивается только тогда, когда количество кораблей в строке indOverflow опустится до 1.
    */

    int indPotentiallyEmpty = N;
    int indOverflow = N;

    //Инициализация значения указателя IndEmpty.
    for (int i = 0; i < N; i++) {
        if (currentNumberOfShipsInRow[i] == 0) {
            indPotentiallyEmpty = i;
            break;
        }
    }

    //Инициализация значения указателя IndOverflow.
    for (int i = 0; i < N; i++) {
        if (currentNumberOfShipsInRow[i] >= 2) {
            indOverflow = i;
            break;
        }
    }

    //Количество шагов, необходимых для оптимального распределения кораблей по строкам.
    int necessaryMoves = 0;

    //Пока пустые строки существуют (необходимо распределение):
    while (indPotentiallyEmpty != N) {

        //Если строка пустая, нужно "передвинуть" сюда корабль.
        if (currentNumberOfShipsInRow[indPotentiallyEmpty] == 0) {
            necessaryMoves += abs(indOverflow - indPotentiallyEmpty);

            //"Передвигаем" корабль из запаса.
            currentNumberOfShipsInRow[indOverflow] -= 1;

            //Если запасных кораблей больше нет, нужно найти следующую переполненную строку.
            if (currentNumberOfShipsInRow[indOverflow] == 1) {
                while (currentNumberOfShipsInRow[indOverflow] < 2) {
                    indOverflow++;
                }
            }
        }

        indPotentiallyEmpty++;
    }

    /*
        Теперь в каждой строке у нас ровно один корабль. Осталось найти столбец такой,
        что количество шагов, необходимых для передвижения прочих кораблей сюда, минимально.

        Инициализируем массив, отражающий количество кораблей в каждом столбце.
            Он, в отличие от предыдущего, не меняется.
    */

    vector<int> numberOfShipsInColumn(N, 0);
    for (int row = 0; row < N; row++) {
        for (auto& ship : ships[row]) {
            numberOfShipsInColumn[ship.second] += 1;
        }
    }

    /*
        Воспользуемся идеями префиксной и постфиксной сумм, и концепцией динамического программирования
        для быстрого нахождения количества ходов до данного столбца из других.
    */

    //Префиксная сумма с индексом i содержит количество кораблей до i-го столбца
    vector<int> prefixSum(N);
    prefixSum[0] = 0;

    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + numberOfShipsInColumn[i - 1];
    }

    //Постфиксная сумма с индексом i содержит количество кораблей после i-го столбца
    vector<int> postfixSum(N);
    postfixSum[N - 1] = 0;

    for (int i = (N - 1) - 1; i >= 0; i--) {
        postfixSum[i] = postfixSum[i + 1] + numberOfShipsInColumn[i + 1];
    }

    /*
        Посчитаем количество ходов, необходимое для передвижения всех кораблей в 0-столбец.
            Поскольку до 0-стобца нет кораблей, используем только постфиксные суммы.
    */

    vector<int> moves(N);

    moves[0] = 0;
    for (int col = 0; col < N; col++) {
        moves[0] += postfixSum[col];
    }

    /*
        Динамически будем вычислять количество ходов, требуемых для построения кораблей в i-ый столбец,
        (считая в отрыве от распределения по строкам) на основе прошлого полученного значения,
        а также префиксной и постфиксной сумм с индексом i, вычитая количество кораблей в данном столбце.

        Поскольку нам нужно минимальное количество ходов для этого, будем выбирать минимум среди
        полученных значений.
    */

    int minColMoves = moves[0];

    for (int col = 1; col < N; col++) {
        moves[col] = moves[col - 1] + prefixSum[col] - postfixSum[col] - numberOfShipsInColumn[col];

        minColMoves = min(moves[col], minColMoves);
    }

    cout << necessaryMoves + minColMoves << "\n";
}

int32_t main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> ships(N);
    pair<int, int> temp;

    for (int i = 0; i < N; i++) {
        cin >> temp.first >> temp.second;

        temp.first -= 1;
        temp.second -= 1;

        ships[temp.first].push_back(temp);
    }

    solve(ships, N);

    return 0;
}