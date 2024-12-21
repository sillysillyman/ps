#include <cstdio>
#include <set>

int n, m;
std::set<int> diff;

int main() {
  scanf("%d%d", &n, &m);
  for (int x, i = 0; i < n; i++) {
    scanf("%d", &x);
    diff.insert(x);
  }
  for (int x, i = 0; i < m; i++) {
    scanf("%d", &x);
    diff.erase(x);
  }
  printf("%zu\n", diff.size());
  for (int x : diff) printf("%d ", x);
}