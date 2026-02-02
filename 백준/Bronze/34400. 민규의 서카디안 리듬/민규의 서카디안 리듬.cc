#include <cstdio>

int main() {
  int T, t;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &t);
    puts(t % 25 < 17 ? "ONLINE" : "OFFLINE");
  }
}