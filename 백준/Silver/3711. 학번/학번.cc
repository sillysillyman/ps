#include <cstdio>
#include <unordered_set>

int arr[300];

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    int G;
    scanf("%d", &G);
    for (int i = 0; i < G; i++) scanf("%d", &arr[i]);

    for (int m = 1;; m++) {
      std::unordered_set<int> us;
      for (int i = 0; i < G; i++) {
        int r = arr[i] % m;
        if (us.find(r) != us.end()) break;
        us.insert(r);
      }
      if (us.size() == G) {
        printf("%d\n", m);
        break;
      }
    }
  }
}