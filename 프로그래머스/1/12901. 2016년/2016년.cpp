#include <string>

using namespace std;

int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
  int day = 0;

  for (int i = 0; i < a - 1; i++) day += months[i];
  return days[(day + b) % 7];
}