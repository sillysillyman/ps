#include <iostream>

using namespace std;

string to_fizzbuzz(int n) {
  if (n % 3 == 0 && n % 5 == 0)
    return "FizzBuzz";
  else if (n % 3 == 0)
    return "Fizz";
  else if (n % 5 == 0)
    return "Buzz";
  else
    return to_string(n);
}

int main() {
  string A, B, C;

  cin >> A >> B >> C;
  if (isdigit(A[0]))
    cout << to_fizzbuzz(stoi(A) + 3);
  else if (isdigit(B[0]))
    cout << to_fizzbuzz(stoi(B) + 2);
  else if (isdigit(C[0]))
    cout << to_fizzbuzz(stoi(C) + 1);
}