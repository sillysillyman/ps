#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    int R, C;
    int lower_row, upper_row;
    int lower_col, upper_col;
    char island[12][12];
    char after_50_island[12][12];
    
    cin >> R >> C;
    lower_row = R; upper_row = 0;
    lower_col = C; upper_col = 0;
    fill(&after_50_island[0][0], &after_50_island[11][12], '.');
    for (int i = 0; i < R + 2; i++) {
        for (int j = 0; j < C + 2; j++) {
            if (i == 0 || i == R + 1 || j == 0 || j == C + 1) island[i][j] = '.';
            else cin >> island[i][j];
        }
    }
    for (int i = 1; i < R + 1; i++) {
        for (int j = 1; j < C + 1; j++) {
            int ocean_cnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (island[nx][ny] == '.') ocean_cnt++;
            }
            if (ocean_cnt >= 3) after_50_island[i][j] = '.';
            else after_50_island[i][j] = island[i][j];
        }
    }
    for (int i = 1; i < R + 1; i++) {
        for (int j = 0; j < C + 1; j++) {
            if (after_50_island[i][j] == 'X') {
                lower_row = min(lower_row, i);
                upper_row = max(upper_row, i);
                lower_col = min(lower_col, j);
                upper_col = max(upper_col, j);
            }
        }
    }
    for (int i = lower_row; i <= upper_row; i++) {
        for (int j = lower_col; j <= upper_col; j++) cout << after_50_island[i][j];
        cout << '\n';
    }
}