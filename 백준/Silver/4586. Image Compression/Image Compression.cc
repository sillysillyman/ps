#include <iostream>

using namespace std;

bool image[64][64];

void compress_image(int x, int y, int width, int threshold) {
  if (width == 1) return;

  int cnt = 0;

  for (int i = x; i < x + width; i++) {
    for (int j = y; j < y + width; j++) {
      if (image[i][j]) cnt++;
    }
  }
  if (cnt >= (double)width * width * threshold / 100) {
    for (int i = x; i < x + width; i++) {
      for (int j = y; j < y + width; j++) image[i][j] = true;
    }
  } else if (cnt <= width * width - (double)width * width * threshold / 100) {
    for (int i = x; i < x + width; i++) {
      for (int j = y; j < y + width; j++) image[i][j] = false;
    }
  }
  compress_image(x, y, width / 2, threshold);
  compress_image(x, y + width / 2, width / 2, threshold);
  compress_image(x + width / 2, y, width / 2, threshold);
  compress_image(x + width / 2, y + width / 2, width / 2, threshold);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int k = 1;; k++) {
    int W, T;

    cin >> W;
    if (W == 0) break;
    cin >> T;
    for (int i = 0; i < W; i++) {
      string line;

      cin >> line;
      for (int j = 0; j < W; j++) image[i][j] = line[j] - '0';
    }
    compress_image(0, 0, W, T);
    cout << "Image " << k << ":\n";
    for (int i = 0; i < W; i++) {
      for (int j = 0; j < W; j++) cout << image[i][j];
      cout << '\n';
    }
  }
}