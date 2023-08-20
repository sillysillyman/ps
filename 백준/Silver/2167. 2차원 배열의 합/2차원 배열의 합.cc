#include <iostream>

using namespace std;

int arr[300][300];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }

    int K;
    int i, j, x, y;

    cin >> K;
    while (K--) {
        int sum = 0;

        cin >> i >> j >> x >> y;
        for (int k = i - 1; k < x; k++) {
            for (int l = j - 1; l < y; l++) sum += arr[k][l];
        }
        cout << sum << '\n';
    }
}