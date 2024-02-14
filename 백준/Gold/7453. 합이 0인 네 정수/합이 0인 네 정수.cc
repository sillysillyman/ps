#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> A, B, C, D, AB, CD;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long cnt = 0;

  cin >> n;
  A.resize(n);
  B.resize(n);
  C.resize(n);
  D.resize(n);
  for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      AB.push_back(A[i] + B[j]);
      CD.push_back(C[i] + D[j]);
    }
  }
  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());
  for (int num : AB) {
    if (!binary_search(CD.begin(), CD.end(), -num)) continue;

    int lower = lower_bound(CD.begin(), CD.end(), -num) - CD.begin();
    int upper = upper_bound(CD.begin(), CD.end(), -num) - CD.begin();

    cnt += (upper - lower);
  }
  cout << cnt;
}