#include <iostream>

using namespace std;

int main() {
    int K;
    int area = 0;
    pair<int, int> field[6];

    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> field[i].first >> field[i].second;
        if (i == 0) continue;
        else {
            bool cond1 = (field[i - 1].first == 1 && field[i].first == 3);
            bool cond2 = (field[i - 1].first == 2 && field[i].first == 4);
            bool cond3 = (field[i - 1].first == 3 && field[i].first == 2);
            bool cond4 = (field[i - 1].first == 4 && field[i].first == 1);

            if (cond1 || cond2 || cond3 || cond4) area -= field[i - 1].second*field[i].second;
        }
        if (i == 5 && area == 0) area -= field[5].second*field[0].second;
    }

    int max_width = 0;
    int max_height = 0;

    for (int i = 0; i < 6; i++) {
        if (field[i].first == 1 || field[i].first == 2) max_width = max(max_width, field[i].second);
        else if (field[i].first == 3 || field[i].first == 4) max_height = max(max_height, field[i].second);
    }
    area += max_width*max_height;
    cout << area*K;
}