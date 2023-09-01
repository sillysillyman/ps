#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    int i = 0, j = 0;

    cin >> N >> M >> K;
    while (i < N) {
        if (i*M + j == K) {
            cout << i << " " << j;
            break;
        }
        if (j == M - 1) {
            i++;
            j = 0;
        }
        else j++;
    }
}