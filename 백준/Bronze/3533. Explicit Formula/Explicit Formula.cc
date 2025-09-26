#include <cstdio>

int x = 0;
int arr[10];

int main() {
  for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      x ^= arr[i] || arr[j];
      for (int k = j + 1; k < 10; k++) x ^= arr[i] || arr[j] || arr[k];
    }
  }
  printf("%d", x);
}