#include <iostream>
#define ll long long

using namespace std;

ll pow(ll a, ll b, ll c) {
    if (b == 0) return 1;
    else if (b == 1) return a%c;

    ll x = pow(a, b/2, c)%c;

    if (b%2) return ((((a%c)*x)%c)*x)%c;
    else return (x*x)%c;
}

int main() {
    ll A, B, C;

    cin >> A >> B >> C;
    cout << pow(A, B, C);
}