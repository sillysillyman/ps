#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int rgb_distances[1001][3];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> rgb_distances[i][0] >> rgb_distances[i][1] >> rgb_distances[i][2];
        if (i == 0) continue;
        else {
            rgb_distances[i][0] += min(rgb_distances[i - 1][1], rgb_distances[i - 1][2]);
            rgb_distances[i][1] += min(rgb_distances[i - 1][0], rgb_distances[i - 1][2]);
            rgb_distances[i][2] += min(rgb_distances[i - 1][0], rgb_distances[i - 1][1]);
        }
    }
    cout << *min_element(rgb_distances[N - 1], rgb_distances[N - 1] + 3);
}