#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main() {
  ll resistance;
  string color1, color2, color3;
  map<string, pair<int, int>> info = {
      {"black", {0, 1}},        {"brown", {1, 10}},
      {"red", {2, 100}},        {"orange", {3, 1000}},
      {"yellow", {4, 10000}},   {"green", {5, 100000}},
      {"blue", {6, 1000000}},   {"violet", {7, 10000000}},
      {"grey", {8, 100000000}}, {"white", {9, 1000000000}}};

  cin >> color1 >> color2 >> color3;

  resistance =
      (ll)(info[color1].first * 10 + info[color2].first) * info[color3].second;

  cout << resistance;
}