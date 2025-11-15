#include <cstdio>

int arr[6];

int main() {
  int N, d;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &d);
    arr[d] = 1;
  }
  for (int i = 1; i < 6; i++)
    if (!arr[i]) return printf("YES"), 0;
  printf("NO");
}