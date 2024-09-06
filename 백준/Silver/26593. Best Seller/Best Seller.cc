#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Info {
  char name[9];
  int sales;
  float profit;

  bool operator>(const Info& other) const {
    return profit == other.profit
               ? (sales == other.sales ? strcmp(name, other.name) < 0
                                       : sales > other.sales)
               : profit > other.profit;
  }
};

vector<Info> infos;

int main() {
  char name[9];
  int sales;
  float cost;
  while (~scanf("%s%d%f", name, &sales, &cost)) {
    Info tmp;

    strcpy(tmp.name, name);
    tmp.sales = sales;
    tmp.profit = cost * sales;
    infos.emplace_back(tmp);
  }
  sort(infos.begin(), infos.end(), greater());
  for (auto& info : infos)
    printf("$%.2f - %s/%d\n", info.profit, info.name, info.sales);
}