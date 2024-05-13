#include <iostream>
#include <stack>

using namespace std;

int arr[1'000'000];
int nge[1'000'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  stack<int> stack;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  fill(nge, nge + N, -1);
  for (int i = N - 1; i >= 0; i--) {
    while (!stack.empty() && arr[i] >= stack.top()) stack.pop();
    if (!stack.empty()) nge[i] = stack.top();
    stack.push(arr[i]);
  }
  for (int i = 0; i < N; i++) cout << nge[i] << ' ';
}