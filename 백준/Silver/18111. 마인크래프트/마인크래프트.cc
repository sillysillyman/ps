#include <iostream>

using namespace std;

int field[500][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, B;
    int max_h = 0;
    int min_h = 256;
    int min_time = ~(1<<31);
    int height;
    
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j] >= max_h) max_h = field[i][j];
            if (field[i][j] <= min_h) min_h = field[i][j];
        }
    }
    for (int h = min_h; h <= max_h; h++) {
        int time;
        int inventory_in = 0;
        int inventory_out = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int height_gap = field[i][j] - h;

                if (height_gap > 0) inventory_in += height_gap;
                else if (height_gap < 0) inventory_out -= height_gap;
            }
        }
        if (inventory_in + B >= inventory_out) {
            time = inventory_out + 2*inventory_in;
            if (time <= min_time) {
                min_time = time;
                height = h;
            }
        }
    }
    cout << min_time << ' ' << height;
}