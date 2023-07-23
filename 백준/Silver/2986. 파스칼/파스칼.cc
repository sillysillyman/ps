#include <iostream>

using namespace std;

int main() {
    int N;
    int M;

    cin >> N;
    if (N == 1 || N == 2) M = 1;
    for (int i = 2; i*i <= N; i++) {
        if (N%i == 0) {
            M = N/i;
            break;
        }
    }
    cout << N - M;
}