#include <iostream>

using namespace std;

const int INF = 123456789;
int users[101][101];

int main() {
    int N, M;
    int A, B;
    int min_bacon_num = INF;
    int person;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        users[A][B] = 1;
        users[B][A] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) users[i][j] = 0;
            else if (!users[i][j]) users[i][j] = INF;
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                users[i][j] = min(users[i][j], users[i][k] + users[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        int bacon_num = 0;

        for (int j = 1; j <= N; j++) {
            bacon_num += users[i][j];
        }
        if (min_bacon_num > bacon_num) {
            min_bacon_num = bacon_num;
            person = i;
        }
    }
    cout << person;
}