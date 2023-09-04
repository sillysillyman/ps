#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll A, B, C;

    cin >> A >> B;
    C = gcd(A, B);
    while (C--) cout << 1;
}