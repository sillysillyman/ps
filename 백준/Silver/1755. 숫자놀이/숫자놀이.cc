#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int digits[10] = {9, 4, 8, 7, 2, 1, 6, 5, 0, 3};
pair<int, int> nums[99];

int main() {
  int M, N;

  scanf("%d%d", &M, &N);
  for (int i = M; i <= N; i++)
    nums[i - M] = {
        (i > 9 ? 10 * digits[i / 10] + digits[i % 10] : 10 * digits[i]), i};
  sort(nums, nums + N - M + 1);
  for (int i = 0; i < N - M + 1; i++) {
    printf("%d ", nums[i].second);
    if (!((i + 1) % 10)) printf("\n");
  }
}