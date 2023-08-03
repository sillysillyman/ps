#include <iostream>
#define ll long long

using namespace std;

ll combination(int n, int r) {
    if (n == r || r == 0) return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
}

ll combination_with_repetition(int n, int r) {
    return combination(n + r - 1, r);
}

int main() {
    int N, M;
    int cnt = 0;

    cin >> N >> M;
    for (int i = 1; i <= M - N + 1; i++) cnt += i;
    cout << combination_with_repetition(N, M - N);
}