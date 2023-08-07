#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, S;
    int num;
    int cnt = 0;
    vector<int> v;

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    for (int i = 1; i < (1<<N); i++) {
        int sum = 0;

        for (int j = 0; j < N; j++) {
            if (i&(1<<j)) sum += v[j];
        }
        if (sum == S) cnt++;
    }
    cout << cnt;
}