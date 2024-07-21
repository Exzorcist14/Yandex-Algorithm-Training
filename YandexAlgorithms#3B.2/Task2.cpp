#include <bits/stdc++.h>
using namespace std;

void solve() {
    ifstream fin("input.txt");

    queue<int> cardDeck1;
    queue<int> cardDeck2;

    int card;
    for (int i = 0; i < 5; ++i) {
        fin >> card;
        cardDeck1.push(card);
    }
    for (int i = 0; i < 5; ++i) {
        fin >> card;
        cardDeck2.push(card);
    }

    int moves = 0;
    int card1, card2;
    while (!cardDeck1.empty() && !cardDeck2.empty()) {
        card1 = cardDeck1.front();
        cardDeck1.pop();

        card2 = cardDeck2.front();
        cardDeck2.pop();

        if ((card1 > card2) && (card1 != 9 || card2 != 0) || card1 == 0 && card2 == 9) {
            cardDeck1.push(card1);
            cardDeck1.push(card2);
        } else {
            cardDeck2.push(card1);
            cardDeck2.push(card2);
        }

        moves++;

        if (moves > 1000000) {
            break;
        }
    }

    if (cardDeck1.empty()) {
        cout << "second " << moves << "\n";
    } else if (cardDeck2.empty()){
        cout << "first " << moves << "\n";
    } else {
        cout << "botva" << "\n";
    }
}

int main() {
    solve();
    return 0;
}