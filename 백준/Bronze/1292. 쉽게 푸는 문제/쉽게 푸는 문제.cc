#include <iostream>

using namespace std;

int sequence[1000];

int main() {
  int A, B;
  int sum = 0;
  int num = 1;
  int cnt = 0;

  cin >> A >> B;
  for (int i = 0; i < B; i++) {
    sequence[i] = num;
    cnt++;
    if (cnt == num) {
      cnt = 0;
      num++;
    }
    if (A - 1 <= i && i <= B - 1) sum += sequence[i];
  }
  cout << sum;
}