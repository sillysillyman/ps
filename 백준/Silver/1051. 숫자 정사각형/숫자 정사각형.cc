#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    int max_side = 0;
    string num_row;
    int matrix[50][50] = {};

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num_row;
        for (int j = 0; j < M; j++) {
            matrix[i][j] = num_row[j] - '0';
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            int num = matrix[i][j];
            for (int k = j + 1; k < M; k++) {
                if (matrix[i][k] == num) {
                    int side = k - j;
                    if (side >= N - i) break;
                    if ((matrix[i + side][k] == num)&&(matrix[i + side][j] == num)) {
                        if (side > max_side) {
                            max_side = side;
                        }
                    }
                }
            }
        }
    }
    cout << (max_side + 1)*(max_side + 1);
}