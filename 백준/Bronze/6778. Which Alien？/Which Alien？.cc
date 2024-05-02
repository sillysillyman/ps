#include <iostream>

using namespace std;

int main() {
  int antenna, eyes;

  cin >> antenna >> eyes;
  if (3 <= antenna && eyes <= 4) cout << "TroyMartian\n";
  if (antenna <= 6 && 2 <= eyes) cout << "VladSaturnian\n";
  if (antenna <= 2 && eyes <= 3) cout << "GraemeMercurian\n";
}