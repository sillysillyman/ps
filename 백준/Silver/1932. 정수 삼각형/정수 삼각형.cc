#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int **triangle;

    cin >> N;
    triangle = new int*[N];
    for (int i = 0; i < N; i++) triangle[i] = new int[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) cin >> triangle[i][j];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) triangle[i][j] += triangle[i - 1][j];
            else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
            else triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
    }
    cout << *max_element(triangle[N - 1], triangle[N - 1] + N);
    for (int i = 0; i < N; i++) delete[] triangle[i];
    delete[] triangle;
}