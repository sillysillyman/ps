#include <iostream>
#include <vector>

using namespace std;

vector<int> sushis;
int checked[3001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, d, k, c;
  int max_num = 0;

  cin >> N >> d >> k >> c;
  for (int i = 0; i < N; i++) {
    int sushi;

    cin >> sushi;
    sushis.push_back(sushi);
  }
  for (int i = 0; i < k - 1; i++) sushis.push_back(sushis[i]);
  for (int i = 0; i < N; i++) {
    int num = 0;

    fill(checked, checked + 3001, 0);
    for (int j = i; j < i + k; j++) {
      if (checked[sushis[j]]) continue;
      checked[sushis[j]] = 1;
      num++;
    }
    if (!checked[c]) num++;
    max_num = max(max_num, num);
  }
  cout << max_num;
}