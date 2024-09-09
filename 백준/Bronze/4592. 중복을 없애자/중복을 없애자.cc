#include <cstdio>

using namespace std;

int main() {
  int N;

  while (scanf("%d", &N) && N) {
    int prev = -1, curr;

    while (N--) {
      scanf("%d", &curr);
      if (curr != prev) printf("%d ", curr);
      prev = curr;
    }
    printf("$\n");
  }
}