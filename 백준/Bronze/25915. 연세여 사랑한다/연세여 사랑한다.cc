#include <cstdio>

int main() {
  char curr;
  char pwd[12] = "ILOVEYONSEI";
  int dist = 0;

  scanf("%c", &curr);
  for (int i = 0; i < 11; i++) {
    dist += pwd[i] >= curr ? pwd[i] - curr : curr - pwd[i];
    curr = pwd[i];
  }
  printf("%d", dist);
}