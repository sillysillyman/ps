#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int temperatures[100001];
int accumulated[100001];

int main() {
    int N, K;
    vector<int> sum;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temperatures[i];
        if (i == 0) accumulated[0] = temperatures[0];
        else accumulated[i] = accumulated[i - 1] + temperatures[i];
    }
    for (int i = K - 1; i < N; i++) {
        if (i == K - 1) sum.push_back(accumulated[K - 1]);
        else sum.push_back(accumulated[i] - accumulated[i - K]);
    }
    cout << *max_element(sum.begin(), sum.end());
}