#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, k;

    cin >> N >> k;
    
    int *scores = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    sort(scores, scores + N, greater<>());
    cout << scores[k - 1];
    delete[] scores;
}