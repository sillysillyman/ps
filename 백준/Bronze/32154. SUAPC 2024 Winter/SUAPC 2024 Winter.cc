#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);
  printf("%s", N == 1   ? "11\nA B C D E F G H J L M"
               : N < 4  ? "9\nA C E F G H I L M"
               : N == 4 ? "9\nA B C E F G H L M"
               : N < 10 ? "8\nA C E F G H L M"
                        : "8\nA B C F G H L M");
}