#include <iostream>
#include <cmath>

using namespace std;

int grid[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    double dist;
    pair<int, int> student, professor;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) student = {i, j};
            else if (grid[i][j] == 5) professor = {i, j};
        }
    }
    dist = sqrt(pow(student.first - professor.first, 2) + pow(student.second - professor.second, 2));
    if (dist < 5) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    int x1, y1, x2, y2;

    if (student.first > professor.first) {
        x1 = professor.first, x2 = student.first;
    } else {
        x1 = student.first, x2 = professor.first;
    }
    if (student.second > professor.second) {
        y1 = professor.second, y2 = student.second;
    } else {
        y1 = student.second, y2 = professor.second;
    }
    if (x1 == x2) {
        for (int j = y1; j <= y2; j++) {
            if (grid[x1][j] == 1) cnt++;
        }
    } else if (y1 == y2) {
        for (int i = x1; i <= x2; i++) {
            if (grid[i][y1] == 1) cnt++;
        }
    } else {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (grid[i][j] == 1) cnt++;
            }
        }
    }
    if (cnt >= 3) cout << 1;
    else cout << 0;
}