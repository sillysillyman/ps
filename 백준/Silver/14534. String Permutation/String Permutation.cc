#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int idx[6];
    char s[6];

    scanf("%s", s);

    int len = strlen(s);
    for (int i = 0; i < len; i++) idx[i] = i;

    printf("Case # %d:\n", t);
    do {
      for (int i = 0; i < len; i++) printf("%c", s[idx[i]]);
      printf("\n");
    } while (std::next_permutation(idx, idx + len));
  }
}