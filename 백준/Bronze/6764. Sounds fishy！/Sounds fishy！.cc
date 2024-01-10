#include <iostream>

using namespace std;

bool is_increasing(int *depth, int size) {
  for (int i = 1; i < size; ++i) {
    if (depth[i] <= depth[i - 1]) return false;
  }
  return true;
}

bool is_decreasing(int *depth, int size) {
  for (int i = 1; i < size; ++i) {
    if (depth[i] >= depth[i - 1]) return false;
  }
  return true;
}

bool is_constant(int *depth, int size) {
  for (int i = 1; i < size; ++i) {
    if (depth[0] != depth[i]) return false;
  }
  return true;
}

int main() {
  int depth[4];

  for (int i = 0; i < 4; i++) cin >> depth[i];
  if (is_increasing(depth, 4))
    cout << "Fish Rising";
  else if (is_decreasing(depth, 4))
    cout << "Fish Diving";
  else if (is_constant(depth, 4))
    cout << "Fish At Constant Depth";
  else
    cout << "No Fish";
}