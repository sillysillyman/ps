#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    double m1, m2;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == x2 && x2 == x3 && x3 == x1) {
        cout << "WHERE IS MY CHICKEN?";
        return 0;
    } else if (x1 == x2 || x2 == x3 || x3 == x1) {
        cout << "WINNER WINNER CHICKEN DINNER!";
        return 0;
    }
    m1 = (double)(y1 - y2)/(x1 - x2);
    m2 = (double)(y2 - y3)/(x2 - x3);
    if (m1 == m2) cout << "WHERE IS MY CHICKEN?";
    else cout << "WINNER WINNER CHICKEN DINNER!";
}