#include <set>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);    

  int N;
  set<int> nums;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;

    cin >> num;
    nums.insert(num);
  }
  for (int num : nums) cout << num << ' ';
}