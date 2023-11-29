#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string resistance;
  string color1, color2, color3;
  map<string, pair<string, string>> info = {
      {"black", {"0", "1"}},        {"brown", {"1", "10"}},
      {"red", {"2", "100"}},        {"orange", {"3", "1000"}},
      {"yellow", {"4", "10000"}},   {"green", {"5", "100000"}},
      {"blue", {"6", "1000000"}},   {"violet", {"7", "10000000"}},
      {"grey", {"8", "100000000"}}, {"white", {"9", "1000000000"}}};

  cin >> color1 >> color2 >> color3;
  if (color1 == "black" && color2 == "black")
    resistance = "0";
  else {
    resistance =
        info[color1].first + info[color2].first + info[color3].second.substr(1);
    if (resistance[0] == '0') resistance = resistance.substr(1);
  }
  cout << resistance;
}