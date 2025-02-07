#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int k, even = 0, odd = 0;
    scanf("%d", &k);

    while (k--) {
      int n;
      scanf("%d", &n);

      if (n & 1)
        odd += n;
      else
        even += n;
    }

    printf("%s\n", even == odd ? "TIE" : even > odd ? "EVEN" : "ODD");
  }
}