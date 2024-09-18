#include <bitset>
#include <cstdio>

std::bitset<300> A[300], B[300];

int main() {
  int N, cnt = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (int b; scanf("%d", &b) && b) A[i][j] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (int b; scanf("%d", &b) && b) B[j][i] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((A[i] & B[j]).any()) ++cnt;
    }
  }
  printf("%d", cnt);
}