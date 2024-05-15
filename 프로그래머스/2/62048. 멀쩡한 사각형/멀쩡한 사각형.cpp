using namespace std;
using ll = long long;

ll solution(int w, int h) {
  ll answer = 0;

  for (int i = 0; i < h; i++) answer += 2 * (ll)((double)w * i / h);
  return answer;
}