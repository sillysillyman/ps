#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string digits[10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
pair<string, int> nums[99];

int main() {
  short M, N;

  scanf("%hd%hd", &M, &N);
  for (int i = M; i <= N; i++)
    nums[i - M] = {(i > 9 ? digits[i / 10] : "") + digits[i % 10], i};
  sort(nums, nums + N - M + 1);
  for (int i = 0; i < N - M + 1; i++) {
    printf("%hd ", nums[i].second);
    if (!((i + 1) % 10)) printf("\n");
  }
}