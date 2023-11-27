#include <iostream>

using namespace std;

int main() {
  int p1, p2, s1, s2;
  int p_sum, s_sum;

  cin >> p1 >> s1;
  cin >> s2 >> p2;
  p_sum = p1 + p2;
  s_sum = s1 + s2;
  if (p_sum > s_sum)
    cout << "Persepolis";
  else if (p_sum < s_sum)
    cout << "Esteghlal";
  else {
    if (s1 < p2)
      cout << "Persepolis";
    else if (s1 > p2)
      cout << "Esteghlal";
    else
      cout << "Penalty";
  }
}