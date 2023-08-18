#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t = 1;
    double A, B, C;

    cout << fixed;
    cout.precision(3);
    while (true) {
        cin >> A >> B >> C;
        if (A == 0 && B == 0 && C == 0) break;
        cout << "Triangle #" << t << '\n';
        if (A == -1) {
            if (C <= B) cout << "Impossible.\n";
            else {
                A = sqrt(C*C - B*B);
                cout << "a = " << A << '\n';
            }
        } else if (B == -1) {
            if (C <= A) cout << "Impossible.\n";
            else {
                B = sqrt(C*C - A*A);
                cout << "b = " << B << '\n';
            }
        } else if (C == -1) {
            C = sqrt(A*A + B*B);
            cout << "c = " << C << '\n';
        }
        cout << '\n';
        t++;
    }
}