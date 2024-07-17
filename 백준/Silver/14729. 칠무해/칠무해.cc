#include <iostream>

using namespace std;

int cnts[100'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while (N--) {
    float score;

    cin >> score;
    cnts[(int)(1000 * score)]++;
  }
  cout << fixed;
  cout.precision(3);
  for (int cnt = 0, i = 0; i < 100'001; i++) {
    if (cnt == 7) break;
    if (!cnts[i]) continue;
    while (cnts[i]-- && cnt++ < 7) cout << (float)i / 1000 << '\n';
  }
}