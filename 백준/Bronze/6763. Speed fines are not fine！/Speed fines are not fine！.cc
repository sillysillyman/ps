#include <iostream>

using namespace std;

int main() {
  int limit, speed;

  cin >> limit >> speed;
  if (speed <= limit)
    cout << "Congratulations, you are within the speed limit!";
  else {
    cout << "You are speeding and your fine is $";
    if (int diff = speed - limit; 1 <= diff && diff <= 20)
      cout << "100.";
    else if (21 <= diff && diff <= 30)
      cout << "270.";
    else if (31 <= diff)
      cout << "500.";
  }
}