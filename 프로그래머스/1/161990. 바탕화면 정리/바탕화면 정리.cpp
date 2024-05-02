#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
  int lux = wallpaper.size() - 1;
  int luy = wallpaper[0].size() - 1;
  int rdx = 1;
  int rdy = 1;

  for (int i = 0; i < wallpaper.size(); i++) {
    for (int j = 0; j < wallpaper[i].size(); j++) {
      if (wallpaper[i][j] == '#') {
        lux = min(lux, i);
        luy = min(luy, j);
        rdx = max(rdx, i + 1);
        rdy = max(rdy, j + 1);
      }
    }
  }
  return {lux, luy, rdx, rdy};
}