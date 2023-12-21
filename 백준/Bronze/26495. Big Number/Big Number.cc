#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string num;

  cin >> num;
  for (auto digit : num) {
    if (digit == '0') {
      cout << "0000\n";
      cout << "0  0\n";
      cout << "0  0\n";
      cout << "0  0\n";
      cout << "0000\n\n";
    } else if (digit == '1') {
      cout << "   1\n";
      cout << "   1\n";
      cout << "   1\n";
      cout << "   1\n";
      cout << "   1\n\n";
    } else if (digit == '2') {
      cout << "2222\n";
      cout << "   2\n";
      cout << "2222\n";
      cout << "2\n";
      cout << "2222\n\n";
    } else if (digit == '3') {
      cout << "3333\n";
      cout << "   3\n";
      cout << "3333\n";
      cout << "   3\n";
      cout << "3333\n\n";
    } else if (digit == '4') {
      cout << "4  4\n";
      cout << "4  4\n";
      cout << "4444\n";
      cout << "   4\n";
      cout << "   4\n\n";
    } else if (digit == '5') {
      cout << "5555\n";
      cout << "5\n";
      cout << "5555\n";
      cout << "   5\n";
      cout << "5555\n";
    } else if (digit == '6') {
      cout << "6666\n";
      cout << "6\n";
      cout << "6666\n";
      cout << "6  6\n";
      cout << "6666\n\n";
    } else if (digit == '7') {
      cout << "7777\n";
      cout << "   7\n";
      cout << "   7\n";
      cout << "   7\n";
      cout << "   7\n\n";
    } else if (digit == '8') {
      cout << "8888\n";
      cout << "8  8\n";
      cout << "8888\n";
      cout << "8  8\n";
      cout << "8888\n\n";
    } else if (digit == '9') {
      cout << "9999\n";
      cout << "9  9\n";
      cout << "9999\n";
      cout << "   9\n";
      cout << "   9\n\n";
    }
  }
}