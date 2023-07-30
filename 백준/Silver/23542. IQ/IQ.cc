#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> v(2*n);
    vector<int> team(n);

    for (int i = 0; i < 2*n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) team[i] = v[i] + v[2*n - i - 1];
    cout << *max_element(team.begin(), team.end()) - *min_element(team.begin(), team.end());
}