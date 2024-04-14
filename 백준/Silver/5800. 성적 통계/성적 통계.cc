#include <algorithm>
#include <iostream>

using namespace std;

int scores[50];

int main() {
  int K;

  cin >> K;
  for (int N, k = 1; k <= K; k++) {
    int largest_gap = 0;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> scores[i];
    sort(scores, scores + N, greater());
    for (int i = 0; i < N - 1; i++)
      largest_gap = max(largest_gap, scores[i] - scores[i + 1]);
    cout << "Class " << k << '\n'
         << "Max " << scores[0] << ", Min " << scores[N - 1] << ", Largest gap "
         << largest_gap << '\n';
  }
}