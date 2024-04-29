#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int max_width = 0, max_height = 0;

  for (auto& size : sizes) {
    int width = size[0];
    int height = size[1];

    max_width = max(max_width, width > height ? width : height);
    max_height = max(max_height, min(width, height));
  }
  return max_width * max_height;
}