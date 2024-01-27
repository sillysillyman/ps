#include <iostream>

using namespace std;

int main() {
  int N;
  int sum = 0;

  cin >> N;
  while (N--) {
    int width, height;

    cin >> width >> height;
    if (width == 136) sum += 1000;
    else if (width == 142) sum += 5000;
    else if (width == 148) sum += 10000;
    else if (width == 154) sum += 50000;
  }
  cout << sum;
}