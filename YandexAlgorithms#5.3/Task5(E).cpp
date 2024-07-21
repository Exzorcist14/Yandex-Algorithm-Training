#include <bits/stdc++.h>

#define int long long

using namespace std;

void input(int& n1, int& n2, int& n3, unordered_set<int>& list1,
           unordered_set<int>& list2, unordered_set<int>& list3, unordered_set<int>& allNumbers) {

    int temp;

    cin >> n1;
    while (n1 --> 0) {
        cin >> temp;
        list1.insert(temp);
        allNumbers.insert(temp);
    }

    cin >> n2;
    while (n2 --> 0) {
        cin >> temp;
        list2.insert(temp);
        allNumbers.insert(temp);
    }

    cin >> n3;
    while (n3 --> 0) {
        cin >> temp;
        list3.insert(temp);
        allNumbers.insert(temp);
    }
}

void solve() {
    int n1, n2, n3;
    unordered_set<int> list1;
    unordered_set<int> list2;
    unordered_set<int> list3;
    unordered_set<int> allNumbers;
    input(n1, n2, n3, list1, list2, list3, allNumbers);

    set<int> numbers;
    bool entryList1 = false;
    bool entryList2 = false;
    bool entryList3 = false;

    for (auto& number : allNumbers) {

        if (list1.contains(number)) {
            entryList1 = true;
        }

        if (list2.contains(number)) {
            entryList2 = true;
        }

        if (entryList1 && entryList2) {
            numbers.insert(number);
        }

        if (list3.contains(number)) {
            entryList3 = true;
        }

        if (entryList1 && entryList3 || entryList2 && entryList3) {
            numbers.insert(number);
        }

        entryList1 = false;
        entryList2 = false;
        entryList3 = false;
    }

    for (auto& number : numbers) {
        cout << number << " ";
    }
    cout << "\n";
}

int32_t main() {
    solve();

    return 0;
}
