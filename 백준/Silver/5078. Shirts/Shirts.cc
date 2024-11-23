#include <algorithm>
#include <cstdio>

struct Shirt {
  char size[3];

  bool operator<(const Shirt& other) const {
    return size[0] == other.size[0] ? size[1] < other.size[1]
                                    : size[0] > other.size[0];
  }
};

int main() {
  int W, H;

  while (scanf("%d", &W) && W) {
    Shirt shirts[60];

    for (int i = 0; i < W; i++) scanf("%s", shirts[i].size);
    scanf("%d", &H);
    for (int i = 0; i < H; i++) scanf("%s", shirts[W + i].size);
    std::sort(shirts, shirts + W + H);
    for (int i = 0; i < W + H; i++) printf("%s ", shirts[i].size);
    puts("");
  }
}