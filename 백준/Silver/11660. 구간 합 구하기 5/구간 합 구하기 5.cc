#include <iostream>

using namespace std;

int matrix[1024][1024];
int accumulated[1024][1024];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int x1, y1, x2, y2;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if (j == 0) accumulated[i][j] = matrix[i][j];
            else accumulated[i][j] = accumulated[i][j - 1] + matrix[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int sum = 0;
        
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        for (int j = x1; j <= x2; j++) {
            if (y1 == 0) sum += accumulated[j][y2];    
            else sum += accumulated[j][y2] - accumulated[j][y1 - 1];
        }
        cout << sum << '\n';
    }
}

// 1 2 3 4
// 2 3 4 5
// 3 4 5 6
// 4 5 6 7

// 1   3   6   10
// 2   5   9   14
// 3   7  12   18
// 4   9  15   22