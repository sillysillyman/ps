#include <iostream>

using namespace std;

int tiles[1000001];

int main() {
    int N;

    cin >> N;
    tiles[1] = 1;
    tiles[2] = 2;
    for (int i = 3; i <= N; i++) tiles[i] = (tiles[i - 2] + tiles[i - 1])%15746;
    cout << tiles[N];
}