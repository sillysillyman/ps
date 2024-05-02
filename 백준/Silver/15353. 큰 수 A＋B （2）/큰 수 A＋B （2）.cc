#include <iostream>

using namespace std;

int main() {
  string A, B, sum;

  cin >> A >> B;
  if (A.size() < B.size()) swap(A, B);
  for (int i = A.size() - B.size(); i > 0; i--) B = '0' + B;

  int carry = 0;

  for (int i = A.size() - 1; i >= 0; i--) {
    int digit_sum = A[i] - '0' + B[i] - '0' + carry;

    carry = digit_sum / 10;
    digit_sum %= 10;
    sum = to_string(digit_sum) + sum;
  }
  if (carry) sum = '1' + sum;
  cout << sum;
}