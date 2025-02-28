#include <cstdio>

int main() {
  int N, L, cnt = 0;
  scanf("%d%d", &N, &L);

  for (int i = 1; cnt != N; i++) {
    bool flag = true;
    int num = i;
    while (num) {
      if (num % 10 == L) {
        flag = false;
        break;
      }
      num /= 10;
    }
    if (flag) ++cnt;
    if (cnt == N) printf("%d", i);
  }
}