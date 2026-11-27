#include <cstdio>

int main() {
  int p, s, h = 1;
  while (scanf("%d%d", &p, &s) && p)
    printf("Hole #%d\n%s\n\n", h++,
           s == 1       ? "Hole-in-one."
           : s == p - 3 ? "Double eagle."
           : s == p - 2 ? "Eagle."
           : s == p - 1 ? "Birdie."
           : s == p     ? "Par."
           : s == p + 1 ? "Bogey."
                        : "Double Bogey.");
}