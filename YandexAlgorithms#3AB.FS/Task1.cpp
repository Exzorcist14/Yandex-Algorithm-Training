#include <bits/stdc++.h>
#define int long long
using namespace std;

class Train {
private:
    stack<pair<int, string>> carrieges;
    unordered_map<string, int> numbers;
public:
    void Add(int number, string goods) {
        carrieges.emplace(number, goods);
        numbers[goods] += number;
    }

    void Delete(int needToDelete) {
        while (needToDelete != 0) {
            auto [number, goods] = carrieges.top();
            if (number <= needToDelete) {
                carrieges.pop();
                numbers[goods] -= number;

                needToDelete -= number;
            } else {
                carrieges.top().first -= needToDelete;
                numbers[goods] -= needToDelete;

                needToDelete = 0;
            }
        }
    }

    int Get(string goods) {
        return numbers[goods];
    }
};

void solve() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    Train train;

    string operation;
    int number;
    string goods;

    while (N --> 0) {
        fin >> operation;

        if (operation == "add") {
            fin >> number >> goods;

            train.Add(number, goods);
        } else if (operation == "delete") {
            fin >> number;

            train.Delete(number);
        } else {
            fin >> goods;

            cout << train.Get(goods) << "\n";
        }
    }
}

int32_t main() {
    solve();
    return 0;
}