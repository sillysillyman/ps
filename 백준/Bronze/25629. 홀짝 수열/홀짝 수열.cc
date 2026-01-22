#include <cstdio>

int N, a, odd, even;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &a);
    a % 2 ? ++odd : ++even;
  }
  printf("%d", odd >= even && odd - even < 2);
}