#include <bits/stdc++.h>

#define int long long

using namespace std;

/*
    Находит массив булевых переменных, показывающих наличие хотя бы одного четнего числа после данного
    на основе того факта, что произведение всех последующих чисел будет четным, если в нем есть хотя бы
    одно четное число (используются постфиксные произведения).
*/

vector<bool> findParityOfPostfixProducts(const vector<int>& seq) {
    vector<bool> result(seq.size());

    result[seq.size() - 1] = seq[seq.size() - 1] % 2 == 0;

    for (int i = (seq.size() - 1) - 1; i >= 0; i--) {
        result[i] = (seq[i] % 2 == 0 || result[i + 1]);
    }

    return result;
}

/*
    Возвращает true, если за текущим числом есть хотя бы одно четное число, иначе false.
*/

bool findPresenceOfEvenNumberNext(const vector<bool>& parityOfPostfixProducts, int currInd) {
    return currInd != parityOfPostfixProducts.size() - 1 && parityOfPostfixProducts[currInd + 1];
}

/*
    Нечетное число - некий "полюс". Он суммируется с четным произведением до и после.
    В результате получается нечетное значение:
    Ч * Н * Ч = Н
*/

string arrangeOperatorsWithSubsequentEven(const vector<int>& seq, int oddInd) {
    string seqOperators = "";

    for (int _ = 0; _ < oddInd - 1; _++) {
        seqOperators += "x";
    }

    //Если первое нечетное число не является первым, то до него точно есть четные.
    if (oddInd != 0) {
        seqOperators += "+";
    }

    if (oddInd != seq.size() - 1) {
        seqOperators += "+";
    }

    for (int _ = oddInd + 1; _ < seq.size() - 1; _++) {
        seqOperators += "x";
    }

    return seqOperators;
}

/*
    Нечетное число - некий "полюс". Он суммируется с четным произведением до и умножается с нечетными после.
    В результате получается нечетное значение:
    Ч * Н * Н = Н
*/

string arrangeOperatorsWithoutSubsequentEven(const vector<int>& seq, int oddInd) {
    string seqOperators = "";

    for (int _ = 0; _ < oddInd - 1; _++) {
        seqOperators += "x";
    }

    //Если первое нечетное число не является первым, то до него точно есть четные.
    if (oddInd != 0) {
        seqOperators += "+";
    }

    if (oddInd != seq.size() - 1) {
        seqOperators += "x";
    }

    for (int _ = oddInd + 1; _ < seq.size() - 1; _++) {
        seqOperators += "x";
    }

    return seqOperators;
}

void solve(vector<int> seq) {
    string operators;

    vector<bool> parityOfPostfixProducts = findParityOfPostfixProducts(seq);

    /*
        Нужно найти первое нечетное. Очевидно, если мы рассматриваем первое нечетное, шанс того,
        что за ним следует хотя бы одно четное число выше.
    */

    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] % 2 != 0) {
            if (findPresenceOfEvenNumberNext(parityOfPostfixProducts, i)) {
                operators = arrangeOperatorsWithSubsequentEven(seq, i);
            } else {
                operators = arrangeOperatorsWithoutSubsequentEven(seq, i);
            }

            break;
        }
    }

    cout << operators << "\n";
}

int32_t main() {
    int n;

    cin >> n;
    vector<int> seq(n);

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    solve(seq);

    return 0;
}