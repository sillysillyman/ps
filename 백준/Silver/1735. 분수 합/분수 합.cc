#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

long long lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    int A, B, C, D;

    cin >> A >> B >> C >> D;
    if (gcd(A, B) != 1) {
        int gcd_AB = gcd(A, B);

        A /= gcd_AB;
        B /= gcd_AB;
    }
    if (gcd(C, D) != 1) {
        int gcd_CD = gcd(C, D);
        
        C /= gcd_CD;
        D /= gcd_CD;
    }

    long long denominator = lcm(B, D);
    long long numerator = A*denominator/B + C*denominator/D;
    int gcd_fraction = gcd(numerator, denominator);

    denominator /= gcd_fraction;
    numerator /= gcd_fraction;
    cout << numerator << ' ' << denominator;
}