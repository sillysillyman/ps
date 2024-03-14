#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;
  for (int i = N; i >= 1; i--) {
    for (int j = N; j >= 1; j--) {
      if (j <= i)
        cout << '*';
      else
        cout << ' ';
    }
    cout << '\n';
  }
}