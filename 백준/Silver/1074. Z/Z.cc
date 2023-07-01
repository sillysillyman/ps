#include <iostream>

using namespace std;

int visit_cnt = 0;

void visit(int size, int row, int col, int target_row, int target_col) {
    if (row == target_row && col == target_col) {
        cout << visit_cnt;
        return;
    }

    bool condition1 = target_row >= row && target_row < row + size;
    bool condition2 = target_col >= col && target_col < col + size;

    if (condition1 && condition2) {
        size /= 2;
        visit(size, row, col, target_row, target_col);
        visit(size, row, col + size, target_row, target_col);
        visit(size, row + size, col, target_row, target_col);
        visit(size, row + size, col + size, target_row, target_col);
    } else {
        visit_cnt += size*size;
    }
}

int main() {
    int N, r, c;

    cin >> N >> r >> c;
    visit((1 << N), 0, 0, r, c);
}