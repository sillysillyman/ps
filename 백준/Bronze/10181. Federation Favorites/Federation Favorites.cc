#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;

  while (true) {
    int sum = 0;
    vector<int> factors;

    scanf("%d", &n);
    if (n == -1) break;
    for (int i = 1; i < n; i++) {
      if (n % i == 0) {
        sum += i;
        factors.push_back(i);
      }
    }
    if (sum == n) {
      printf("%d = ", n);
      for (int i = 0; i < factors.size(); i++) {
        if (i == factors.size() - 1)
          printf("%d\n", factors[i]);
        else
          printf("%d + ", factors[i]);
      }
    } else
      printf("%d is NOT perfect.\n", n);
  }
}