#include <iostream>

using namespace std;

int main() {
  string A, B;

  cin >> A >> B;
  for (char& c : A) {
    if (c == '6') c = '5';
  }
  for (char& c : B) {
    if (c == '6') c = '5';
  }
  cout << stoi(A) + stoi(B) << ' ';
  for (char& c : A) {
    if (c == '5') c = '6';
  }
  for (char& c : B) {
    if (c == '5') c = '6';
  }
  cout << stoi(A) + stoi(B);
}