#include <cstdio>

float a, b;
int arr[6];

int main() {
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < 6; i++) scanf("%d", &arr[i]);
    if (t) b = 13 * arr[0] + 7 * arr[1] + 5 * arr[2] + 3 * arr[3] + 3 * arr[4] + 2 * arr[5] + 1.5;
    else a = 13 * arr[0] + 7 * arr[1] + 5 * arr[2] + 3 * arr[3] + 3 * arr[4] + 2 * arr[5];
  }
  printf("%s", a > b ? "cocjr0208" : "ekwoo");
}