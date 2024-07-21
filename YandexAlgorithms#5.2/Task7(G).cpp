#include <bits/stdc++.h>

#define int long long

using namespace std;

void solvePart(const vector<int>& currSeq) {
    int currL = 1;
    int currMin = currSeq[0];

    vector<int> sizes;
    int next;

    for (int i = 1; i < currSeq.size(); i++) {
        currMin = min(currSeq[i], currMin);

        //Текущий минимум (возможно, новый) в полуинтервале не меньше увеличенной длины?
        if ((currMin >= (currL + 1))) {
            currL++; //Добавляем число в полуинтервал
        } else {
            sizes.push_back(currL); //Полуинтервал превращается в отрезок, начинается новый полуинтервал
            currMin = currSeq[i];
            currL = 1;
        }
    }

    sizes.push_back(currL); //Закрываем последний полуинтервал, превращая его в отрезок

    cout << sizes.size() << "\n";
    for (int i = 0; i < sizes.size(); i++) {
        cout << sizes[i] << " ";
    }
    cout << "\n";
}

void solve(const vector<vector<int>>& seq) {
    for (int i = 0; i < seq.size(); i++) {
        solvePart(seq[i]);
    }
}

int32_t main() {
    int t;
    cin >> t;

    int n;
    vector<vector<int>> seq;

    vector<int> tempSeq;
    int temp;

    while (t --> 0) {
        cin >> n;

        while (n --> 0) {
            cin >> temp;
            tempSeq.push_back(temp);
        }

        seq.push_back(tempSeq);
        tempSeq.clear();
    }

    solve(seq);

    return 0;
}
