#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int H;
    int max_height;
    long long height_sum;
    vector<int> heights;

    cin >> N >> M;
    while (N--) {
        cin >> H;
        heights.push_back(H);
    }

    int lower = 0;
    int upper = *max_element(heights.begin(), heights.end());
    while (lower <= upper) {
        long long mid = (lower + upper)/2;

        height_sum = 0;
        for (int height : heights) {
            if (height > mid) height_sum += (height - mid);
        }
        if (height_sum < M) upper = mid - 1;
        else {
            max_height = mid;
            lower = mid + 1;
        }
    }
    cout << max_height;
}