#include <algorithm>
#include <iostream>

using namespace std;

struct Birthday {
  int day, month, year;
  string name;
};

Birthday birthdays[100];

int main() {
  int n;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> birthdays[i].name >> birthdays[i].day >> birthdays[i].month >>
        birthdays[i].year;
  sort(birthdays, birthdays + n, [](const Birthday& a, const Birthday& b) {
    if (a.year == b.year) {
      if (a.month == b.month) return a.day > b.day;
      return a.month > b.month;
    }
    return a.year > b.year;
  });
  cout << birthdays[0].name << '\n' << birthdays[n - 1].name;
}