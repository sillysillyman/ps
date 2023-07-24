#include <iostream>

using namespace std;

int N, M;
char map[201][201];

int main() {
    int cnt = 0;
    string line;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) map[i][j] = line[j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'E' || map[i][j] == 'I') {
                if (i - 3 >= 0) {
                    if (map[i - 1][j] == 'N' || map[i - 1][j] == 'S') {
                        if (map[i - 2][j] == 'F' || map[i - 2][j] == 'T') {
                            if (map[i - 3][j] == 'J' || map[i - 3][j] == 'P') cnt++;
                        }
                    }
                }
                if (i - 3 >= 0 && j + 3 < M) {
                    if (map[i - 1][j + 1] == 'N' || map[i - 1][j + 1] == 'S') {
                        if (map[i - 2][j + 2] == 'F' || map[i - 2][j + 2] == 'T') {
                            if (map[i - 3][j + 3] == 'J' || map[i - 3][j + 3] == 'P') cnt++;
                        }
                    }
                }
                if (j + 3 < M) {
                    if (map[i][j + 1] == 'N' || map[i][j + 1] == 'S') {
                        if (map[i][j + 2] == 'F' || map[i][j + 2] == 'T') {
                            if (map[i][j + 3] == 'J' || map[i][j + 3] == 'P') cnt++;
                        }
                    }
                }
                if (i + 3 < N && j + 3 < M) {
                    if (map[i + 1][j + 1] == 'N' || map[i + 1][j + 1] == 'S') {
                        if (map[i + 2][j + 2] == 'F' || map[i + 2][j + 2] == 'T') {
                            if (map[i + 3][j + 3] == 'J' || map[i + 3][j + 3] == 'P') cnt++;
                        }
                    }
                }
                if (i + 3 < N) {
                    if (map[i + 1][j] == 'N' || map[i + 1][j] == 'S') {
                        if (map[i + 2][j] == 'F' || map[i + 2][j] == 'T') {
                            if (map[i + 3][j] == 'J' || map[i + 3][j] == 'P') cnt++;
                        }
                    }
                }
                if (i + 3 < N && j - 3 >= 0) {
                    if (map[i + 1][j - 1] == 'N' || map[i + 1][j - 1] == 'S') {
                        if (map[i + 2][j - 2] == 'F' || map[i + 2][j - 2] == 'T') {
                            if (map[i + 3][j - 3] == 'J' || map[i + 3][j - 3] == 'P') cnt++;
                        }
                    }
                }
                if (j - 3 >= 0) {
                    if (map[i][j - 1] == 'N' || map[i][j - 1] == 'S') {
                        if (map[i][j - 2] == 'F' || map[i][j - 2] == 'T') {
                            if (map[i][j - 3] == 'J' || map[i][j - 3] == 'P') cnt++;
                        }
                    }
                }
                if (i - 3 >= 0 && j - 3 >= 0) {
                   if (map[i - 1][j - 1] == 'N' || map[i - 1][j - 1] == 'S') {
                        if (map[i - 2][j - 2] == 'F' || map[i - 2][j - 2] == 'T') {
                            if (map[i - 3][j - 3] == 'J' || map[i - 3][j - 3] == 'P') cnt++;
                        }
                    } 
                }
            }
        }
    }
    cout << cnt;
}