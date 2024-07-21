#include <bits/stdc++.h>
using namespace std;

int translate(string& mark) {
    string h, m, s;
    h += mark[0]; h += mark[1];
    m += mark[3]; m += mark[4];
    s += mark[6]; s += mark[7];
    return stoi(h) * 3600 + stoi(m) * 60 + stoi(s);
}

string format(int R, int remainder) {
    string result;

    int addM = 0;
    if (R % 3600 % 60 + remainder == 60) {
        ++addM;
    }

    int addH = 0;
    if ((R % 3600) / 60 + addM >= 60) {
        ++addH;
    }



    if ((R / 3600 + addH) % 24 < 10) {
        result += '0';
    }

    result += to_string((R / 3600 + addH) % 24);
    R %= 3600;
    result += ':';

    if ((R / 60 + addM) % 60 < 10) {
        result += '0';
    }

    result += to_string((R / 60 + addM) % 60);
    R %= 60;
    result += ':';

    if ((R + remainder) % 60 < 10) {
        result += '0';
    }
    result += to_string((R + remainder) % 60);

    return result;
}

void solve() {
    ifstream fin("input.txt");

    int A, B, C;
    string mark;

    fin >> mark;
    A = translate(mark);

    fin >> mark;
    B = translate(mark);

    fin >> mark;
    C = translate(mark);

    int diff;
    if (C > A) {
        diff = C - A;
    } else {
        diff = C + (86400 - A);
    }

    cout << format(B + diff / 2, diff % 2) << "\n";
}

int main() {
    solve();
    return 0;
}