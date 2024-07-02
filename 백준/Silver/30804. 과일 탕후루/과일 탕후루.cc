#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 200'000;
int fruits[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, max_cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> fruits[i];

  int left = 0, right = 0, cnt = 0;
  unordered_map<int, int> cnts;

  while (right < N) {
    ++cnts[fruits[right++]];
    ++cnt;
    if (cnts.size() > 2) {
      cnts[fruits[left]]--;
      if (cnts[fruits[left]] == 0) {
        cnts.erase(fruits[left]);
      }
      ++left;
      --cnt;
    }
    max_cnt = max(max_cnt, cnt);
  }
  cout << max_cnt;
}