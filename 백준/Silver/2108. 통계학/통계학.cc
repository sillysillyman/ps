#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int arr[8001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int sum = 0, avg, median, mode, range;

  cin >> N;
  for (int num, min_val, max_val, i = 0; i < N; i++) {
    cin >> num;
    sum += num;
    arr[num + 4000]++;
    if (i == 0) {
      min_val = num;
      max_val = num;
    }
    min_val = min(min_val, num);
    max_val = max(max_val, num);
    range = max_val - min_val;
  }
  avg = round(float(sum) / N);
  for (int cnt = 0, i = 0; i < 8001; i++) {
    if (arr[i] && cnt <= N / 2 + 1 && N / 2 + 1 <= cnt + arr[i]) {
      median = i - 4000;
      break;
    }
    cnt += arr[i];
  }
  mode = max_element(arr, arr + 8001) - arr;
  if (int mode_candidate = max_element(arr + mode + 1, arr + 8001) - arr;
      arr[mode] == *(mode_candidate + arr))
    mode = mode_candidate - 4000;
  else
    mode -= 4000;
  cout << avg << '\n' << median << '\n' << mode << '\n' << range;
}