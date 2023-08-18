#include <iostream>

using namespace std;

int main() {
    int T;
    int A, B, C;

    cin >> T;
    A = T/300;
    T %= 300;
    B = T/60;
    T %= 60;
    C = T/10;
    T %= 10;
    if (T) cout << -1;
    else cout << A << " " << B << " " << C;
}