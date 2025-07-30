#include <cstdio>

int N, C;
char arr[(int)1e4];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf(" %c", &arr[i]);
  for (int i = 0; i < N; i++) {
    char c;
    scanf(" %c", &c);
    C += c == arr[i];
  }
  printf("%d", C);
}