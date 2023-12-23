#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> socks;

  for (int i = 0; i < 5; i++) {
    int num;

    cin >> num;
    socks[num]++;
  }
  for (auto sock : socks) {
    if (sock.second % 2) {
      cout << sock.first;
      break;
    }
  }
}