#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;
queue<int> discards;

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) q.push(i);
  for (int i = 0; q.size() > 1; i++) {
    if (i % 2) {
      q.push(q.front());
      q.pop();
    } else {
      discards.push(q.front());
      q.pop();
    }
  }
  while (!discards.empty()) {
    printf("%d ", discards.front());
    discards.pop();
  }
  printf("%d", q.front());
}