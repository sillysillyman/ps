#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X;
    int num;
    vector<int> v;
    vector<int> accumulated;

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
        if (i == 0) accumulated.push_back(num);
        else accumulated.push_back(accumulated[i - 1] + num);
    }
    if (*max_element(v.begin(), v.end()) == 0) {
        cout << "SAD";
        return 0;
    }

    int max_visited = 0;
    int cnt = 0;

    for (int i = X - 1; i < N; i++) {
        if (i == X - 1) max_visited = accumulated[X - 1];
        else max_visited = max(max_visited, accumulated[i] - accumulated[i - X]);
    }
    for (int i = X - 1; i < N; i++) {
        if (i == X - 1 && accumulated[i] == max_visited) cnt++;
        else if (accumulated[i] - accumulated[i - X] == max_visited) cnt++;
    }
    cout << max_visited << '\n' << cnt;
}