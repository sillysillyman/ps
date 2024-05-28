#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
  int answer = 0;
  vector<int> cnts;
  map<int, int> cnt_map;

  for (int& size : tangerine) ++cnt_map[size];
  for (auto& [size, cnt] : cnt_map) cnts.push_back(cnt);
  sort(cnts.begin(), cnts.end(), greater());
  for (int cnt : cnts) {
    k -= cnt;
    ++answer;
    if (k <= 0) break;
  }
  return answer;
}