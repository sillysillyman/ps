#include <iostream>
#include <map>

using namespace std;

int primes[100000];

void eras() {
    fill(primes, primes + 100000, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < 100000; i++) {
        if (primes[i]) {
            for (int j = 2; i*j < 100000; j++) primes[i*j] = 0;
        }
    }
}

int main() {
    int T, N;

    cin >> T;
    eras();
    while (T--) {
        map<int, int> decomposed;

        cin >> N;
        for (int i = 2; i <= N; i++) {
            if (N == 0) break;
            if (primes[i] && N%i == 0) {
                N /= i;
                decomposed[i]++;
                i--;
            }
        }
        for (auto i : decomposed) cout << i.first << ' ' << i.second << '\n';
    }
}