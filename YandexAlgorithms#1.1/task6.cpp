#include <iostream>

using namespace std;


int main() {
    int x1, y1, x2, y2;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    int sMin = (x1+x2)*(y1+y2);

    int sum = x1 + x2;
    int oMax = (y1 > y2 ? y1 : y2);

    int mult1;
    int mult2;

    if (sum * oMax < sMin) {
        mult1 = sum;
        mult2 = oMax;
        sMin = sum * oMax;
    }

    sum = (x1 + y2);
    oMax = (y1 > x2 ? y1 : x2);

    if ((x1 + y2) * oMax < sMin) {
        mult1 = sum;
        mult2 = oMax;
        sMin = sum * oMax;
    }

    sum = (y1 + x2);
    oMax = (x1 > y2 ? x1 : y2);

    if ((y1 + x2) * oMax < sMin) {
        mult1 = sum;
        mult2 = oMax;
        sMin = sum * oMax;
    }

    sum = (y1 + y2);
    oMax = (x1 > x2 ? x1 : x2);

    if ((y1 + y2) * oMax < sMin) {
        mult1 = sum;
        mult2 = oMax;

    }

    cout << mult1 << " " << mult2 << endl;

    return 0;
}
