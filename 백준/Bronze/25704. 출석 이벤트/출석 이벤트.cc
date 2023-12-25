#include <iostream>

using namespace std;

int main() {
  int N, P;
  int discounted;

  cin >> N >> P;
  discounted = P;
  if (N >= 5) discounted = (P - 500 > 0 ? P - 500 : 0);
  if (N >= 10) discounted = min(discounted, (int)(0.9 * P));
  if (N >= 15) discounted = min(discounted, (P - 2000 > 0 ? P - 2000 : 0));
  if (N >= 20) discounted = min(discounted, (int)(0.75 * P));
  cout << discounted;
}