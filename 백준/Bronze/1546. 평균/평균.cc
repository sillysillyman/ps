#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int sum = 0;
        
    cin >> N;

    int *scores = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    sort(scores, scores + N);
    for (int i = 0; i < N; i++) {
        sum += scores[i];
    }
    cout << float(sum)*100/N/scores[N - 1];
}