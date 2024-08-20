#include <cstdio>

int main() {
  int X, Y, N;

  scanf("%d%d%d", &X, &Y, &N);
  for (int i = 1; i <= N; i++) {
    if (!(i % X) && !(i % Y))
      printf("FizzBuzz\n");
    else if (!(i % X))
      printf("Fizz\n");
    else if (!(i % Y))
      printf("Buzz\n");
    else
      printf("%d\n", i);
  }
}