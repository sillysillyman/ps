#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num;
    vector<int> x1;

    cin >> N;
    while (N--) {
        cin >> num;
        x1.push_back(num);
    }

    vector<int> x2(x1);

    sort(x2.begin(), x2.end());
    x2.erase(
                unique(x2.begin(), x2.end()),
                x2.end()
                );
    for (int x : x1) {
        cout << lower_bound(x2.begin(), x2.end(), x) - x2.begin() << ' ';
    }
}