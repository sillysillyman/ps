#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> arr;

  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    vector<int> tmp;

    tmp.push_back(n);
    tmp.push_back(i);
    while (*(&tmp.back() - 1) - tmp.back() >= 0)
      tmp.push_back(*(&tmp.back() - 1) - tmp.back());
    if (tmp.size() > arr.size()) arr = tmp;
  }
  printf("%zu\n", arr.size());
  for (int num : arr) printf("%d ", num);
}