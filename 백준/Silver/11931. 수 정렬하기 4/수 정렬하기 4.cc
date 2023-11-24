#include <algorithm>
#include <iostream>

using namespace std;

int nums[1000000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> nums[i];
  sort(nums, nums + N, greater<>());
  for (int i = 0; i < N; i++) cout << nums[i] << '\n';
}