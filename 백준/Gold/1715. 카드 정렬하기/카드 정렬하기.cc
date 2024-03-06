#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int cnt = 0;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    pq.push(num);
  }
  while (pq.size() > 1) {
    int compare = 0;

    compare += pq.top();
    pq.pop();
    compare += pq.top();
    pq.pop();
    pq.push(compare);
    cnt += compare;
  }
  cout << cnt;
}