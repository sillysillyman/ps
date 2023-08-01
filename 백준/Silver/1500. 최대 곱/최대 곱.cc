#include <iostream>

using namespace std;

int main() {
    int S, K;
    
    cin >> S >> K;

    long long q = S/K;
    long long sum = q*K;
    long long res = 1;

    for (int i = 0; i < S - sum; i++) res *= (q + 1);
    for (int i = 0; i < K - S + sum; i++) res *= q;
    cout << res;
}