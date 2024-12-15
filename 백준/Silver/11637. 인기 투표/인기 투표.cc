#include <cstdio>

int arr[10];

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int n, sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      sum += arr[i];
    }

    int winner, max_vote = 0;
    for (int i = 0; i < n; i++) {
      if (max_vote == arr[i])
        winner = -1;
      else if (max_vote < arr[i]) {
        winner = i + 1;
        max_vote = arr[i];
      }
    }

    if (winner == -1)
      puts("no winner");
    else
      printf("%s winner %d\n", (max_vote > sum / 2 ? "majority" : "minority"),
             winner);
  }
}