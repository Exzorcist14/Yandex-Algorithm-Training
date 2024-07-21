#include <bits/stdc++.h>

#define int long long

using namespace std;

//Строит матрицу префиксных сумм
void buildMatrixPrefixSum(vector<vector<int>>& matrixPrefixSum, vector<vector<int>>& field, int& n, int& m) {
    //Выстраиваем столбцы, преобразуя в матрицу
    vector<int> temp(m);

    for (int i = 0; i < n; i++) {
        matrixPrefixSum.push_back(temp);
    }

    //Квадрат (0;0)
    matrixPrefixSum[0][0] = field[0][0];

    //Строка 0
    for (int j = 1; j < m; j++) {
        matrixPrefixSum[0][j] = matrixPrefixSum[0][j - 1] + field[0][j];
    }

    //Столбец 0
    for (int i = 1; i < n; i++) {
        matrixPrefixSum[i][0] = matrixPrefixSum[i - 1][0] + field[i][0];
    }

    //Инициализация остальной части матрицы
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            matrixPrefixSum[i][j] = matrixPrefixSum[i][j - 1] +
                                    matrixPrefixSum[i - 1][j] -
                                    matrixPrefixSum[i - 1][j - 1] +
                                    field[i][j];
        }
    }
}

//Считает сумму внутри прямоугольника, задаваемый диагональными точками
int calculateSumInRectangle(pair<int, int>& leftTop, pair<int, int>& rightBottom, vector<vector<int>>& matrixPrefixSum) {
    int leftBottomArea;
    if (leftTop.second - 1 >= 0) {
        leftBottomArea = matrixPrefixSum[rightBottom.first][leftTop.second - 1];
    } else {
        leftBottomArea = 0;
    }

    int topRightArea;
    if (leftTop.first - 1 >= 0) {
        topRightArea = matrixPrefixSum[leftTop.first - 1][rightBottom.second];
    } else {
        topRightArea = 0;
    }

    int leftTopArea;
    if (leftTop.first - 1 >= 0 && leftTop.second - 1 >= 0) {
        leftTopArea = matrixPrefixSum[leftTop.first - 1][leftTop.second - 1];
    } else {
        leftTopArea = 0;
    }

    int s = matrixPrefixSum[rightBottom.first][rightBottom.second] -
            leftBottomArea - topRightArea + leftTopArea;

    return s;
}

//Определяет, существует ли крест при таком k
bool isTherePlus(int& k, vector<vector<int>> matrixPrefixSum, int& n, int& m) {

    //Горизонтальный прямоугольник
    int lwX, lwY;
    int rwX, rwY;

    //Вертикальный прямоугольник
    int lhX, lhY;
    int rhX, rhY;

    pair<int, int> leftTop;
    pair<int, int> rightBottom;

    int curWS;
    int curHS;

    for (int i = 0; i <= n - 3*k; i++) {

        for (int j = 0; j <= m - 3*k; j++) {

            lwX = i + k;
            lwY = j;

            rwX = lwX + k - 1;
            rwY = lwY + 3*k - 1;

            leftTop = {lwX, lwY};
            rightBottom = {rwX, rwY};
            curWS = calculateSumInRectangle(leftTop, rightBottom, matrixPrefixSum);

            lhX = i;
            lhY = j + k;

            rhX = lhX + 3*k - 1;
            rhY = lhY + k - 1;

            leftTop = {lhX, lhY};
            rightBottom = {rhX, rhY};
            curHS = calculateSumInRectangle(leftTop, rightBottom, matrixPrefixSum);

            //Условие образования плюса
            if (curWS == curHS && curWS == k * 3*k) {
                return true;
            }
        }
    }

    return false;
}

//Правый бинарный поиск по ответу
int rightBinarySearch(vector<vector<int>> matrixPrefixSum, int& n, int& m) {

    int l = 1;
    int r = min(n, m);
    int mid;

    while (l != r) {
        mid = (l + r + 1) / 2;

        if (isTherePlus(mid, matrixPrefixSum, n,m)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return r;
}

void solve() {
    ifstream fin("input.txt");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> field;
    vector<int> tempF(m);
    for (int i = 0; i < n; i++) {
        field.push_back(tempF);
    }

    char buff;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> buff;
            field[i][j] = (buff == '#' ? 1 : 0);
        }
    }

    vector<vector<int>> matrixPrefixSum;
    buildMatrixPrefixSum(matrixPrefixSum, field, n, m);

    cout << rightBinarySearch(matrixPrefixSum, n, m) << "\n";
}

int32_t main() {
    solve();
    return 0;
}
