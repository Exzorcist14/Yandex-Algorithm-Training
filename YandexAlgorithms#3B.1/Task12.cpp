#include <bits/stdc++.h>

using namespace std;

int bracketType(char& bracket) {
    switch (bracket) {
        case '(':
            return 1;
        case ')':
            return -1;
        case '[':
            return 2;
        case ']':
            return -2;
        case '{':
            return 3;
        case '}':
            return -3;
    }
}

void solve() {
   ifstream fin("input.txt");
   char bracket;

   stack<char> bracketStack;
   bool flag = true;
   int type;

   while (fin >> bracket){
       type = bracketType(bracket);
       if (type < 0) {
           if (bracketStack.size() == 0 || abs(type) != bracketType(bracketStack.top())) {
               flag = false;
               break;
           } else {
               bracketStack.pop();
           }
       } else {
           bracketStack.push(bracket);
       }
   }

   if (flag && bracketStack.size() == 0) {
       cout << "yes" << "\n";
   } else {
       cout << "no" << "\n";
   }
}

int main() {
    solve();
    return 0;
}