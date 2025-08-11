#include <cstdio>

float a, b;
int v[6];

int main() {
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < 6; i++) scanf("%d", &v[i]);
    if (t) b = 13 * v[0] + 7 * v[1] + 5 * v[2] + 3 * v[3] + 3 * v[4] + 2 * v[5] + 1.5;
    else a = 13 * v[0] + 7 * v[1] + 5 * v[2] + 3 * v[3] + 3 * v[4] + 2 * v[5];
  }
  printf("%s", a > b ? "cocjr0208" : "ekwoo");
}