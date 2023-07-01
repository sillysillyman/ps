#include <iostream>

using namespace std;

int main() {
    int N, M, cnt = 0;
    string S, p = "I";

    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) p += "OI";
    for (int i = 0; i < M; i++) {
        if (S.substr(i, 2*N + 1) == p) cnt++;
    }
    cout << cnt;
}