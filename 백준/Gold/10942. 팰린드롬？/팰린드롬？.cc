#include <iostream>

using namespace std;

int arr[2'001];
bool palindrome[2'001][2'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 1; i <= N; i++) palindrome[i][i] = 1;
  for (int i = 1; i < N; i++) palindrome[i][i + 1] = arr[i] == arr[i + 1];
  for (int j = 3; j <= N; j++)
    for (int i = j - 2; i > 0; i--)
      palindrome[i][j] = (arr[i] == arr[j]) && palindrome[i + 1][j - 1];

  cin >> M;
  while (M--) {
    int s, e;
    cin >> s >> e;
    cout << palindrome[s][e] << '\n';
  }
}