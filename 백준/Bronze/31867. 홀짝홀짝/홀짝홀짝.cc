#include <cstdio>

using namespace std;

int main() {
  int N, odd_cnt = 0, even_cnt = 0;

  scanf("%d\n", &N);
  while (N--) {
    char digit;

    scanf("%c", &digit);
    if ((digit - '0') & 1)
      ++odd_cnt;
    else
      ++even_cnt;
  }
  printf("%d", odd_cnt == even_cnt ? -1 : (odd_cnt < even_cnt ? 0 : 1));
}