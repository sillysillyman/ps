#include <iostream>
#include <map>

using namespace std;

int main() {
  string school;
  map<string, string> abbreviations = {
      {"NLCS", "North London Collegiate School"},
      {"BHA", "Branksome Hall Asia"},
      {"KIS", "Korea International School"},
      {"SJA", "St. Johnsbury Academy"}};

  cin >> school;
  cout << abbreviations[school];
}