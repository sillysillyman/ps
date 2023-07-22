#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int T;
    int A, B;

    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << A*B/gcd(A, B) << '\n';
    }
}