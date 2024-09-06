#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Info {
  string name;
  int sales;
  double profit;

  bool operator>(const Info& other) const {
    return profit == other.profit ? (sales == other.sales ? name < other.name
                                                          : sales > other.sales)
                                  : profit > other.profit;
  }
};

ostream& operator<<(ostream& os, Info& info) {
  os << '$' << info.profit << " - " << info.name << '/' << info.sales;
  return os;
}

vector<Info> infos;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string name;
  int sales;
  double cost;
  while (cin >> name >> sales >> cost)
    infos.push_back({name, sales, cost * sales});
  sort(infos.begin(), infos.end(), greater());
  cout << fixed;
  cout.precision(2);
  for (auto& info : infos) cout << info << '\n';
}