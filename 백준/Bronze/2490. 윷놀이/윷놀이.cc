#include <iostream>

using namespace std;

int main() {
  for (int i = 0; i < 3; i++) {
    int head = 0, tail = 0;

    for (int yut, j = 0; j < 4; j++) {
      cin >> yut;
      if (yut)
        tail++;
      else
        head++;
    }
    if (head == 1 && tail == 3)
      cout << "A\n";
    else if (head == 2 && tail == 2)
      cout << "B\n";
    else if (head == 3 && tail == 1)
      cout << "C\n";
    else if (head == 4)
      cout << "D\n";
    else if (tail == 4)
      cout << "E\n";
  }
}