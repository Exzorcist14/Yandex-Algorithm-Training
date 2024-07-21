#include <bits/stdc++.h>

#define int long long

using namespace std;

bool hasEnemyBeenDestroyed(int y, int enemySoldiers) {
    return (y + enemySoldiers) <= 0;
}

bool haveWeLost(int x, int y, int enemySoldiers) {
    return x <= 0 && !(hasEnemyBeenDestroyed(y, enemySoldiers));
}

int attackBarracksFirst(int x, int y, int p, int moves) {
    /*
        Атакуем казарму, пока она не будет уничтожена.
        Пока атакуем казарму, теряем текущее p бойцов, а у противника становится на p бойцов больше.
        Если в ход разрушения казармы остались силы - атакуем на них бойцов.
        Затем атакуем сопротивляющихся солдат пробивника, пока их не победим.
    */

    int enemySoldiers = p;

    while (y > 0) {
        if (haveWeLost(x, y, enemySoldiers)) {
            return -1;
        }

        //Первая фаза
        y -= x;
        enemySoldiers += (y < 0 ? y : 0); //Может, мы нанесли избыточное количество урона казарме?

        //Вторая фаза
        x -= enemySoldiers;

        //Третья фаза
        if (y > 0) {
            enemySoldiers += p;
        }

        moves++;
    }

    if (haveWeLost(x, y, enemySoldiers)) {
        return -1;
    }

    //Подкреплений больше нет.

    while (enemySoldiers > 0) {
        if (haveWeLost(x, y, enemySoldiers)) {
            return -1;
        }

        enemySoldiers -= x; //Первая фаза
        x -= enemySoldiers; //Вторая фаза

        moves++;
    }

    //Избыток урона уже не интересен, поскольку не меняет число ходов.

    return moves;
}

void solve(int x, int y, int p) {
    int bestGame = 10000;

    //Первый ход однозначен: все x солдат бьют казарму, так как у врага нет бойцов, а затем у врага появляется p бойцов

    y -= x;
    if (hasEnemyBeenDestroyed(y, 0)) { //Игра закончилась ещё до появления солдат врага?
        cout << 1 << "\n";
        return;
    }

    int enemySoldiers = p;

    /*
        Теперь у нас есть два сценария - атаковать вражин (и остаток в казарму) {1} или
        атаковать здесь и сейчас казарму, а потом силы противника {2}

        Будем пробовать пойти по второму сценарию каждый раз,
        запуская отдельное моделирование игры. Найдя количество ходов при такой игре,
        пробуем продолжить вариант {1}. Повторяем, пытаясл найти лучший исход, если он существует
    */

    //Второй и последующий ходы

    int movesWhenAttacking;

    for (int moves = 1; moves <= 5000; moves++) {
        //Симулируем приоритетную атаку казарм
        movesWhenAttacking = attackBarracksFirst(x, y, p, moves); //Текущий ход выполнится внутри до следующей итерации

        if (movesWhenAttacking != -1) {
            bestGame = min(bestGame, movesWhenAttacking);
        }

        //Симулируем приоритетную атаку бойцов
        y -= (x - p);

        if (hasEnemyBeenDestroyed(y, 0)) {
            bestGame = min(bestGame, moves + 1); //Текущий ход выполнился здесь, на этой итерации --> moves + 1
        }
    }

    if (bestGame == 10000) {
        bestGame = -1;
    }

    cout << bestGame << "\n";
}

int32_t main() {
    int x, y, p;
    cin >> x >> y >> p;

    solve(x, y, p);

    return 0;
}