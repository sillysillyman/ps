#include <vector>

using namespace std;
using ll = long long;

vector<ll> solution(vector<ll> numbers) {
  vector<ll> answer;

  for (ll number : numbers) {
    ll mask = 1;

    while (true) {
      if (mask & number)
        mask <<= 1;
      else
        break;
    }
    answer.push_back(number + (mask == 1 ? 1 : mask >> 1));
  }
  return answer;
}