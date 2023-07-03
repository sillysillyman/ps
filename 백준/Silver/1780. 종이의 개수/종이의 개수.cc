#include <iostream>

using namespace std;

int num_of_minus_one = 0;
int num_of_zero = 0;
int num_of_one = 0;
int paper[2187][2187];

void separate_paper(int row, int col, int size) {
    bool is_identical = true;
    int first_num = paper[row][col];

    for (int i = row; i < (row + size); i++) {
        for (int j = col; j < (col + size); j++) {
            if (paper[i][j] != first_num) {
                is_identical = false;
                break;
            }
        }
        if (!is_identical) break;
    }
    if (is_identical) {
        if (first_num == -1) num_of_minus_one++;
        else if (first_num == 0) num_of_zero++;
        else if (first_num == 1) num_of_one++;
        return;
    }
    separate_paper(row, col, size/3);
    separate_paper(row, col + size/3, size/3);
    separate_paper(row, col + 2*size/3, size/3);
    separate_paper(row + size/3, col, size/3);
    separate_paper(row + size/3, col + size/3, size/3);
    separate_paper(row + size/3, col + 2*size/3, size/3);
    separate_paper(row + 2*size/3, col, size/3);
    separate_paper(row + 2*size/3, col + size/3, size/3);
    separate_paper(row + 2*size/3, col + 2*size/3, size/3);
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    separate_paper(0, 0, N);
    cout << num_of_minus_one << '\n';
    cout << num_of_zero << '\n';
    cout << num_of_one << '\n';
}