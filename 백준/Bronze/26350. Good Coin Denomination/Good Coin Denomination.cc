#include <cstdio>

int arr[11];

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int d, flag = 0;
    scanf("%d", &d);
    for (int i = 1; i <= d; i++) {
      scanf("%d", &arr[i]);
      if (arr[i] < 2 * arr[i - 1] && !flag) flag = 1;
    }
    printf("Denominations: ");
    for (int i = 1; i <= d; i++) printf("%d ", arr[i]);
    printf("\n%s coin denominations!\n\n", flag ? "Bad" : "Good");
  }
}