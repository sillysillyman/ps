#include <cstdio>

int main() {
  int N, n;
  int arr[3] = {};
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &n);
    arr[++n]++;
  }
  puts(arr[1] > N / 2 ? "INVALID" : arr[2] > arr[0] ? "APPROVED" : "REJECTED");
}