#include <iostream>
#include <cmath>

using namespace std;

bool is_squared(int num) {
    return sqrt(num) == int(sqrt(num));
}

int main() {
    int N, M;
    int matrix[9][9] = {};
    int max_square_num = -1;
    string nums_row;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> nums_row;
        for (int j = 0; j < M; j++) matrix[i][j] = nums_row[j] - '0';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = -N; k < N; k++) {
                for (int l = -M; l < M; l++) {
                    if(!k && !l) continue;
                    int r = i;
                    int c = j;
                    int num = 0;

                    while (0 <= r && r < N && 0 <= c && c < M) {
                        num *= 10;
                        num += matrix[r][c];
                        r += k;
                        c += l;
                        if (is_squared(num)) max_square_num = max(max_square_num, num);
                    }
                }
            }
        }
    }
    cout << max_square_num;
}