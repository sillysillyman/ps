#include <map>
#include <vector>

using namespace std;
using ll = long long;

ll solution(vector<int> weights) {
  ll answer = 0;
  map<int, ll> weight_map;

  for (int weight : weights) ++weight_map[weight];
  for (auto& [weight, cnt] : weight_map) {
    if (cnt > 1) answer += cnt * (cnt - 1) / 2;
    if (!(weight % 2) && weight_map.find(3 * weight / 2) != weight_map.end())
      answer += cnt * weight_map[3 * weight / 2];
    if (weight_map.find(2 * weight) != weight_map.end())
      answer += cnt * weight_map[2 * weight];
    if (!(weight % 3) && weight_map.find(4 * weight / 3) != weight_map.end())
      answer += cnt * weight_map[4 * weight / 3];
  }
  return answer;
}