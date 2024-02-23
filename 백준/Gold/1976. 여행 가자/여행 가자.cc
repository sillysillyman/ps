#include <iostream>

using namespace std;

int parents[201];

int find(int x) {
  if (parents[x] == x) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y)
    parents[y] = x;
  else
    parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int connected;

      cin >> connected;
      if (connected) merge(i, j);
    }
  }

  int first_city;

  cin >> first_city;
  for (int city, i = 1; i < M; i++) {
    cin >> city;
    if (find(city) != find(first_city)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}