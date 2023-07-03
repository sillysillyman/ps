#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return  a*b/gcd(a, b);
}

int main() {
    int T;
    int M, N, x, y;
    int final_year;
    int k;

    cin >> T;
    while (T--) {
        k = -1;
        cin >> M >> N >> x >> y;
        final_year = lcm(M, N);
        while (x <= final_year) {
            if ((x - 1)%N + 1 == y || x > final_year) break;
            x += M;
        }
        if (x > final_year) cout << -1 << endl;
        else cout << x << endl;
    }
}