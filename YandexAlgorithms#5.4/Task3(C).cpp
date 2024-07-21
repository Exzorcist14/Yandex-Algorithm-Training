#include <bits/stdc++.h>

#define int long long

using namespace std;

//l - количество полков, s - количество орков, которое должно отправиться
int rightBinSearch(int l, int s, vector<int>& uruk_haiWedge) {
    int left = 0;
    int right = uruk_haiWedge.size() - l;
    int mid;

    int uruk_hais;

    while (left != right) {
        mid = (left + right + 1) / 2;

        uruk_hais = uruk_haiWedge[mid + l - 1] -
                    (mid - 1 >= 0 ? uruk_haiWedge[mid - 1] : 0);

        if (uruk_hais < s) {
            left = mid;
        } else if (uruk_hais == s)  {
            return mid;
        } else {
            right = mid - 1;
        }
    }

    uruk_hais = uruk_haiWedge[right + l - 1] -
                (right - 1 >= 0 ? uruk_haiWedge[right - 1] : 0);

    return (uruk_hais == s ? right : -2);
}

void solve() {
    ifstream fin("input.txt");

    int n, m;
    fin >> n >> m;

    vector<int> uruk_haiRegiments(n); //Полки урук-хай
    for (int i = 0; i < n; i++) {
        fin >> uruk_haiRegiments[i];
    }

    vector<int> uruk_haiWedge(n); //Префиксные суммы количества уруков до этого полка
    uruk_haiWedge[0] = uruk_haiRegiments[0];
    for (int i = 1; i < n; i++) {
        uruk_haiWedge[i] = uruk_haiWedge[i - 1] + uruk_haiRegiments[i];
    }

    int l, s;
    vector<int> uruk_haiCrews(m); //Номера полков

    for (int i = 0; i < m; i++) {
        fin >> l >> s;
        uruk_haiCrews[i] = rightBinSearch(l, s, uruk_haiWedge) + 1;
    }

    for (auto& crew : uruk_haiCrews) {
        cout << crew << "\n";
    }
}

int32_t main() {
    solve();
    return 0;
}
