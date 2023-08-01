#include <iostream>

using namespace std;

int main() {
    int S, K;
    
    cin >> S >> K;

    int q = S/K;
    int s = q*K;
    long long res = 1;

    for (int i = 0; i < S - s; i++) res *= (q + 1);
    for (int i = 0; i < K - S + s; i++) res *= q;
    cout << res;
}