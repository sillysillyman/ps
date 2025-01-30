#include <algorithm>
#include <cstdio>

struct Press {
  int idx, time;
  char key;

  bool operator<(const Press& other) const {
    return time == other.time ? idx < other.idx : time < other.time;
  }
};

Press arr[1'000];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  for (int i = 0; i < M; i++)
    scanf("%d%d %c", &arr[i].idx, &arr[i].time, &arr[i].key);
  std::sort(arr, arr + M);
  for (int i = 0; i < M; i++) putchar(arr[i].key);
}