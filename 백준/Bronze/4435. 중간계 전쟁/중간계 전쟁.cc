#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int hobbits, good_men, elves, dwarves, eagles, good_wizrds;
    int orcs, evil_men, wargs, goblins, uruk_hai, trolls, evil_wizrds;

    scanf("%d %d %d %d %d %d", &hobbits, &good_men, &elves, &dwarves, &eagles,
          &good_wizrds);
    scanf("%d %d %d %d %d %d %d", &orcs, &evil_men, &wargs, &goblins, &uruk_hai,
          &trolls, &evil_wizrds);

    int good = hobbits + 2 * good_men + 3 * elves + 3 * dwarves + 4 * eagles +
               10 * good_wizrds;
    int bad = orcs + 2 * evil_men + 2 * wargs + 2 * goblins + 3 * uruk_hai +
              5 * trolls + 10 * evil_wizrds;
    printf("Battle %d: ", t);
    if (good > bad)
      printf("Good triumphs over Evil\n");
    else if (good < bad)
      printf("Evil eradicates all trace of Good\n");
    else
      printf("No victor on this battle field\n");
  }
}