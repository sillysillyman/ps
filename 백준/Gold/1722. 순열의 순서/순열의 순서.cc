#include <iostream>
#include <vector>

using namespace std;

bool visited[21];
long long factorials[21];

int main() {
  factorials[0] = 1;
  for (int i = 1; i < 21; i++) factorials[i] = i * factorials[i - 1];

  int N, num;

  cin >> N >> num;
  fill(visited + 1, visited + N + 1, false);
  if (num == 1) {
    long long k;
    vector<int> v(N + 1);

    cin >> k;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (visited[j]) continue;
        if (k <= factorials[N - i]) {
          v[i] = j;
          visited[j] = true;
          break;
        } else
          k -= factorials[N - i];
      }
    }
    for (int i = 1; i <= N; i++) cout << v[i] << ' ';
  } else if (num == 2) {
    long long k = 1;
    vector<int> v(N + 1);

    for (int num, i = 1; i <= N; i++) {
      cin >> num;
      v[i] = num;
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j < v[i]; j++) {
        if (visited[j]) continue;
        k += factorials[N - i];
      }
      visited[v[i]] = true;
    }
    cout << k;
  }
}