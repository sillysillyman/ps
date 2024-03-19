#include <iostream>

using namespace std;

int heights[50];

int main() {
  int N, max_view = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> heights[i];
  for (int i = 0; i < N; i++) {
    int left_view = 0, right_view = 0;
    double left_slope = 1e9, right_slope = -1e9;

    for (int j = i - 1; j >= 0; j--) {
      double slope = (double)(heights[i] - heights[j]) / (i - j);

      if (slope < left_slope) {
        left_view++;
        left_slope = slope;
      }
    }
    for (int j = i + 1; j < N; j++) {
      double slope = (double)(heights[i] - heights[j]) / (i - j);

      if (slope > right_slope) {
        right_view++;
        right_slope = slope;
      }
    }
    max_view = max(max_view, left_view + right_view);
  }
  cout << max_view;
}