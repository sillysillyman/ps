#include <iostream>

using namespace std;

int main() {
  char curr;
  int dist = 0;
  string pwd = "ILOVEYONSEI";

  cin >> curr;
  for (char& next : pwd) {
    dist += abs(next - curr);
    curr = next;
  }
  cout << dist;
}