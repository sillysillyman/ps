#include <cstdio>

using namespace std;

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int X;
    int cnt = 0;
    int digits[10] = {};

    scanf("%d", &X);
    while (X) {
      digits[X % 10] = 1;
      X /= 10;
    }
    for (int i = 0; i < 10; i++) cnt += digits[i];
    printf("%d\n", cnt);
  }
}