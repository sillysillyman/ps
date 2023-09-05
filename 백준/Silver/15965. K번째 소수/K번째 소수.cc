#include <iostream>

using namespace std;

int primes[10000000];

void eratos() {
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < 10000000; i++) primes[i] = 1;
    for (int i = 2; i < 10000000; i++) {
        if (primes[i]) {
            for (int j = 2; j*i < 10000000; j++) primes[j*i] = 0;
        }
    }
}

int main() {
    int K;

    cin >> K;
    eratos();
    for (int i = 0; i < 10000000; i++) {
        if (primes[i]) K--;
        if (K == 0) {
            cout << i;
            break;
        }
    }
}