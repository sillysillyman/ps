#include <algorithm>
#include <cstdio>

using namespace std;

int B, C, D, total, discounted;
int burger[1'000], side[1'000], beverage[1'000];

int main() {
  scanf("%d%d%d", &B, &C, &D);
  for (int i = 0; i < B; i++) {
    scanf("%d", &burger[i]);
    total += burger[i];
  }
  for (int i = 0; i < C; i++) {
    scanf("%d", &side[i]);
    total += side[i];
  }
  for (int i = 0; i < D; i++) {
    scanf("%d", &beverage[i]);
    total += beverage[i];
  }
  sort(burger, burger + B, greater());
  sort(side, side + C, greater());
  sort(beverage, beverage + D, greater());

  int n = min({B, C, D});
  for (int i = 0; i < n; i++)
    discounted += (burger[i] + side[i] + beverage[i]) / 10 * 9;
  for (int i = n; i < B; i++) discounted += burger[i];
  for (int i = n; i < C; i++) discounted += side[i];
  for (int i = n; i < D; i++) discounted += beverage[i];

  printf("%d\n%d", total, discounted);
}