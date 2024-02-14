#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, n, m;
  long long cnt = 0;

  cin >> T;
  cin >> n;
  for (int num, i = 0; i < n; i++) {
    cin >> num;
    A.push_back(num);
  }
  for (int i = 0; i < n; i++) {
    int sum = A[i];

    for (int j = i + 1; j < n; j++) {
      sum += A[j];
      A.push_back(sum);
    }
  }
  cin >> m;
  for (int num, i = 0; i < m; i++) {
    cin >> num;
    B.push_back(num);
  }
  for (int i = 0; i < m; i++) {
    int sum = B[i];

    for (int j = i + 1; j < m; j++) {
      sum += B[j];
      B.push_back(sum);
    }
  }
  sort(B.begin(), B.end());
  for (int num : A) {
    int t = T - num;
    int lower = lower_bound(B.begin(), B.end(), t) - B.begin();
    int upper = upper_bound(B.begin(), B.end(), t) - B.begin();

    cnt += (upper - lower);
  }
  cout << cnt;
}