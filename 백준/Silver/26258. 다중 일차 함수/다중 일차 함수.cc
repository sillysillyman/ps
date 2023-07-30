#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int x, y;
    int Q;
    double k;
    vector<pair<int, int>> points;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }
    cin >> Q;
    while (Q--) {
        cin >> k;

        int low = 0;
        int high = points.size() - 1;
        int mid;

        while (low < high) {
            mid = (low + high)/2;
            if (low + 1 == high) break;
            if (points[mid].first < k) low = mid;
            else high = mid;
        }
        if (points[mid].second < points[mid + 1].second) cout << 1 << '\n';
        else if (points[mid].second > points[mid + 1].second) cout << -1 << '\n';
        else cout << 0 << '\n';
    }
}