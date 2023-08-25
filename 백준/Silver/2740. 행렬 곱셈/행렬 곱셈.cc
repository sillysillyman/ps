#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    
    cin >> N >> M;

    int **matrix1 = new int*[N];
    
    for (int i = 0; i < N; i++) matrix1[i] = new int[M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix1[i][j];
        }
    }
    cin >> M >> K;

    int **matrix2 = new int*[M];

    for (int i = 0; i < M; i++) matrix2[i] = new int[K];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> matrix2[i][j];
        }
    }

    int **matrix = new int*[N];

    for (int i = 0; i < N; i++) matrix[i] = new int[K];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int num = 0;

            for (int k = 0; k < M; k++) {
                num += matrix1[i][k]*matrix2[k][j];
            }
            matrix[i][j] = num;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++) delete[] matrix1[i];
    delete[] matrix1;
    for (int i = 0; i < M; i++) delete[] matrix2[i];
    delete[] matrix2;
    for (int i = 0; i < N; i++) delete[] matrix[i];
    delete[] matrix;
}  