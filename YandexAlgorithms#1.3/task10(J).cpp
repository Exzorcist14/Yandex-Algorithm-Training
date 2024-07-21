#include <bits/stdc++.h>

#define int long long

using namespace std;

//Проверяет, лежит ли точка внутри области на основе того, заключена ли она между 6-ю прямыми
bool insideArea(const int& x, const int& y, vector<int>& minX, vector<int>& maxX,
                vector<int>& minY, vector<int>& maxY) {

    //Отсекает прямоугольник
    if (!((x >= minX[0] && x <= maxX[0]) && (y >= minY[0] && y <= maxY[0]))) {
        return false;
    }

    //Уравнение прямой - (y - y1) == (x - x1) * tg, где tg = (y2 - y1) / (x2 - x1)

    //1) Правая верхняя прямая: tg = -1
    if (((y - maxX[2]) > (x - maxX[0]) * -1)) {
        return false;
    }

    //2) Левая верхняя прямая: tg = 1
    if (((y - minX[2]) > (x - minX[0]) * 1)) {
        return false;
    }

    //3) Левая нижняя прямая: tg = -1
    if ((y - minY[0]) < (x - minY[1]) * -1) {
        return false;
    }

    //4) Правая нижняя прямая: tg = 1
    if (((y - minY[0]) < (x - minY[2]) * 1)) {
        return false;
    }

    return true;
}

//Переопределяет крайние точки новой области.
//Применяется ко второй и далее входящим в текущую область точкам
void redefineExtremes(const int& x, const int& y, vector<int>& minX, vector<int>& maxX,
                      vector<int>& minY, vector<int>& maxY) {

    if (x < minX[0]) {
        minX[0] = x;
        minX[1] = y;
        minX[2] = y;
    } else if (x == minX[0]) {
        if (y > minX[2]) {
            minX[2] = y;
        } else if (y < minX[1]) {
            minX[1] = y;
        }
    } else if (x > maxX[0]) {
        maxX[0] = x;
        maxX[1] = y;
        maxX[2] = y;
    } else if (x == maxX[0]) {
        if (y > maxX[2]) {
            maxX[2] = y;
        } else if (y < maxX[1]) {
            maxX[1] = y;
        }
    }

    if (y < minY[0]) {
        minY[0] = y;
        minY[1] = x;
        minY[2] = x;
    } else if (y == minY[0]) {
        if (x > minY[2]) {
            minY[2] = x;
        } else if (x < minY[1]) {
            minY[1] = x;
        }
    } else if (y > maxY[0]) {
        maxY[0] = y;
        maxY[1] = x;
        maxY[2] = x;
    } else if (y == maxY[0]) {
        if (x > maxX[2]) {
            maxX[2] = x;
        } else if (x < maxX[1]) {
            maxX[1] = x;
        }
    }
}

//Инициализирует крайние точки новой области.
//Применяется к первой входящей в текущую область точке
void initializeNewArea(const int& x, const int& y, vector<int>& minX, vector<int>& maxX,
                       vector<int>& minY, vector<int>& maxY) {

    minX[0] = x;
    minX[1] = y;
    minX[2] = y;

    maxX[0] = x;
    maxX[1] = y;
    maxX[2] = y;

    minY[0] = y;
    minY[1] = x;
    minY[2] = x;

    maxY[0] = y;
    maxY[1] = x;
    maxY[2] = x;
}

//Отсеивает из текущей области точки, лежащие на расстоянии не более d от точки, указанной навигатором
void weedOut(const int& d, const int& x, const int& y, vector<int>& minX, vector<int>& maxX,
             vector<int>& minY, vector<int>& maxY) {

    vector<int> newMinX(3);
    vector<int> newMaxX(3);
    vector<int> newMinY(3);
    vector<int> newMaxY(3);

    bool isFirst = true;

    for (int i = -d; i <= d; i++) {
        for (int j = -d; j <= d; j++) {
            if (abs(i) + abs(j) <= d) {
                int currX = x + i;
                int currY = y + j;

                if (insideArea(currX, currY, minX, maxX, minY, maxY)) {
                    if (!isFirst) {
                        redefineExtremes(currX, currY, newMinX, newMaxX, newMinY, newMaxY);
                    } else {
                        initializeNewArea(currX, currY, newMinX, newMaxX, newMinY, newMaxY);

                        isFirst = false;
                    }
                }
            }
        }
    }

    minX = newMinX;
    maxX = newMaxX;
    minY = newMinY;
    maxY = newMaxY;
}

void solve(const int& t, const int& d, const int& n, const vector<vector<int>>& navigatorsMessage) {
    vector<int> minX(3, 0);
    vector<int> maxX(3, 0);
    vector<int> minY(3, 0);
    vector<int> maxY(3, 0);

    for (int i = 0; i < n; i++) {
        minX[0] -= t;
        maxX[0] += t;
        minY[0] -= t;
        maxY[0] += t;

        weedOut(d, navigatorsMessage[i][0], navigatorsMessage[i][1], minX, maxX, minY, maxY);
    }

    //Вычисление точек, входящих в конечную область
    set<pair<int, int>> possiblePositions;

    for (int x = minX[0]; x <= maxX[0]; x++) {
        for (int y = minY[0]; y <= maxY[0]; y++) {
            if (insideArea(x, y, minX, maxX, minY, maxY)) {
                possiblePositions.insert({x, y});
            }
        }
    }

    //Вывод числа таких точек и их самих
    cout << possiblePositions.size() << "\n";

    for (auto& element : possiblePositions) {
        cout << element.first << " " << element.second << "\n";
    }
}

int32_t main() {
    int t, d, n;
    cin >> t >> d >> n;

    vector<vector<int>> coords;
    vector<int> temp(2);

    for (int i = 0; i < n; i++) {
        cin >> temp[0] >> temp[1];
        coords.push_back(temp);
    }

    solve(t, d, n, coords);

    return 0;
}