#include <iostream>

using namespace std;

int main() {
  char pixel;
  string cat;
  
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      cin >> pixel;
      if (pixel == 'w') cat = "chunbae";
      else if (pixel == 'b') cat = "nabi";
      else if (pixel == 'g') cat = "yeongcheol";
    }
  }
  cout << cat;
}