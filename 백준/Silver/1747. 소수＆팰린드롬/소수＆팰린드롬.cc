#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 10000000;
int primes[MAX];

void eratos() {
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < MAX; i++) primes[i] = 1;
    for (int i = 2; i < MAX; i++) {
        if (primes[i]) {
            for (int j = 2; j*i < MAX; j++) primes[i*j] = 0;
        }
    }
}

bool is_palindrome(int num) {
    bool ret = true;
    string s = to_string(num);

    int len  = s.length();

    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len - i - 1]) ret = false;
    }
    return ret;
}

int main() {
    int N;

    eratos();
    cin >> N;
    for (int i = N; i < MAX; i++) {
        if (primes[i] && is_palindrome(i)) {
            cout << i;
            break;
        }
    }
}