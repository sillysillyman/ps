#include <iostream>
#include <map>

using namespace std;
using ll = long long;

ll arr[200'001];
map<ll, ll> cache;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  ll cnt = 0;

  cin >> N >> K;
  cache[0] = 1;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
    cnt += cache[arr[i] - K];
    cache[arr[i]]++;
  }
  cout << cnt;
}