#include <bits/stdc++.h>

#define int long long

using namespace std;

int rightBinarySearch(int& leftBorder, int& trackSize, vector<int>& keys) {

    int left = leftBorder; // ИНДЕКС!!!!!!!!!!!!
    int right = keys.size() - 1;
    int mid;

    while (left != right) {
        mid = (left + right + 1) / 2;

        if (keys[mid] - keys[leftBorder] <= trackSize - 1) {
            //внутри отрезка {keys[leftBorder], keys[leftBorder + trackSize - 1]}
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return keys[right];
}

bool isSuitable(int& trackSize, vector<int>& keys, unordered_map<int, pair<int, int>>& prefixMinMaxY,
                unordered_map<int, pair<int, int>>& postfixMinMaxY) {

    int leftBorder;
    int rightBorder;

    //ALERT ! ГРАНИЧНЫЕ СЛУЧАИ

    for (int i = 0; i < keys.size(); i++) {

        leftBorder = keys[i];
        rightBorder = rightBinarySearch(i, trackSize, keys); //ALERT

        int maxY = max(prefixMinMaxY[leftBorder].second, postfixMinMaxY[rightBorder].second);
        int minY = min(prefixMinMaxY[leftBorder].first, postfixMinMaxY[rightBorder].first);

        //надо вспомнить про правый конец окна
        if (maxY - minY + 1 <= trackSize) {
            return true;
        }
    }

    return false;
}

int leftBinarySearch(vector<int>& keys, int& w,
                     unordered_map<int, pair<int, int>>& prefixMinMaxY,
                     unordered_map<int, pair<int, int>>& postfixMinMaxY) {

    int left = 1;
    int right = w; // --> EDIT TO min(w, h)
    int mid;

    while (left != right) {

        mid = (left + right) / 2;

        if (isSuitable(mid, keys, prefixMinMaxY, postfixMinMaxY)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}


void solve() {
    //<--------------------------------------------------------------------------------------------------->

    ifstream fin("input.txt");

    int w, h, n;
    fin >> w >> h >> n;

    /*
      Упорядоченный словарь [x - {minY, maxY}.
        Упорядоченность словаря позволяет последовательно передвигаться вправо и влево.
    */

    unordered_map<int, pair<int, int>> pointsForX;
    unordered_map<int, pair<int, int>> pointsForY;
    vector<int> keysX(n);

    int x, y;

    for (int i = 0; i < n; i++) {
        fin >> x >> y;

        //cout << "X = " << x << endl;
        //cout << points[x].first << endl;
        //cout << points[x].second << endl;
        //cout << endl;

        keysX[i] = x;

        if (pointsForX[x].first == 0) {
            pointsForX[x].first = y;
            pointsForX[x].second = y;
        } else if (y < pointsForX[x].first) {
            pointsForX[x].first = y;
        } else if (y > pointsForX[x].second) {
            pointsForX[x].second = y;
        }
    }

    sort(keysX.begin(), keysX.end());
    vector<int> uniqueKeysX; //Отберём уникальные
    uniqueKeysX.push_back(keysX[0]);

    for (int i = 1; i < n; i++) {
        if (keysX[i] != keysX[i - 1]) {
            uniqueKeysX.push_back(keysX[i]);
        }
    }
/*
    for (auto& key : uniqueKeysX) {
        cout << "x = " << key << " | " << pointsForX[key].first << " & " << pointsForX[key].second << "\n";
    }*/

    //<--------------------------------------------------------------------------------------------------->

    /*
        Считаем все точки, упорядочим их, будем находить минимум и максимум по y (частный случай)
        до текущей линии и после (префикс и постфикс).

        Сначала найдём префиксы.
    */

    unordered_map<int, pair<int, int>> prefixMinMaxY; //МОЖНО unordered, обращение будет по ключу x

    int prevMinY;
    int prevMaxY;

    int currMinY = 1000000001;
    int currMaxY = -1000000001;

    for (auto& key : uniqueKeysX) {

        prevMinY = currMinY;
        prevMaxY = currMaxY;

        prefixMinMaxY[key] = {currMinY, currMaxY};

        currMinY = min(pointsForX[key].first, prevMinY);
        currMaxY = max(pointsForX[key].second, prevMaxY);
    }
/*
    cout << "\n" << "PREFIX:" << "\n";
    for (auto& pair : prefixMinMaxY) {
        cout << "x = " << pair.first << " | " << pair.second.first << " & " << pair.second.second << "\n";
    }*/

    //<--------------------------------------------------------------------------------------------------->

    unordered_map<int, pair<int, int>> postfixMinMaxY; //МОЖНО unordered, обращение будет по ключу x

    currMinY = 1000000001;
    currMaxY = -1000000001;

    for (int i = uniqueKeysX.size() - 1; i >= 0; i--) {

        prevMinY = currMinY;
        prevMaxY = currMaxY;

        postfixMinMaxY[uniqueKeysX[i]] = {currMinY, currMaxY};

        currMinY = min(pointsForX[uniqueKeysX[i]].first, prevMinY);
        currMaxY = max(pointsForX[uniqueKeysX[i]].second, prevMaxY);
    }
/*
    cout << "\n" << "POSTFIX:" << "\n";
    for (auto& pair : postfixMinMaxY) {
        cout << "x = " << pair.first << " | " << pair.second.first << " & " << pair.second.second << "\n";
    }*/

    int ans;
    ans = leftBinarySearch(uniqueKeysX, w, prefixMinMaxY, postfixMinMaxY);
    cout << ans << "\n";

    /*
    for (auto& point : pointsForX) {

        if (!(point.first >= 175 && point.first <= 1887 || point.second.first >= 217 && point.second.first <= 1922 &&
        point.second.second >= 217 && point.second.second <= 1922)) {
            cout << point.first << " | " << point.second.first << " & " << point.second.second << endl;
        }

    }


    cout << endl << endl;
    cout << isSuitable(1710, uniqueKeysX, prefixMinMaxY, postfixMinMaxY) << endl;*/

    /*
    int closest = rightBinarySearch(3, 2, keys);
    cout << closest << endl;*/
}

int32_t main() {
    solve();
    return 0;
}

/*



 */