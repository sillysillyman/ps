#include <iostream>
#include <vector>

using namespace std;

int primes[1000000];

void eras() {
    fill(primes, primes + 1000000, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 0; i < 1000000; i++) {
        if (primes[i]) {
            for (int j = 2; i*j < 1000000; j++) primes[i*j] = 0;
        }
    }
}

int main() {
    int N;
    int cnt = 0;

    cin >> N;
    
    vector<int> sequence(N);
    vector<int> accumulated(N);

    eras();
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        if (i == 0) accumulated[0] = sequence[0];
        else accumulated[i] = accumulated[i - 1] + sequence[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (!primes[j - i + 1]) continue;
            if (i == 0) {
                if (primes[accumulated[j]]) cnt++;
            } else {
                if (primes[accumulated[j] - accumulated[i - 1]]) cnt++;
            }
        }
    }
    cout << cnt;
}