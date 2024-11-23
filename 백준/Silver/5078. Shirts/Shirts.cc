#include <algorithm>
#include <iostream>

using namespace std;

struct Shirt {
  char size[3];

  bool operator<(const Shirt& other) const {
    return size[0] == other.size[0] ? size[1] < other.size[1]
                                    : size[0] > other.size[0];
  }

  friend istream& operator>>(istream& in, Shirt& s) {
    in >> s.size;
    return in;
  }

  friend ostream& operator<<(ostream& out, const Shirt& s) {
    out << s.size;
    return out;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int W, H;

  while (cin >> W && W) {
    Shirt shirts[60];

    for (int i = 0; i < W; i++) cin >> shirts[i];
    cin >> H;
    for (int i = 0; i < H; i++) cin >> shirts[W + i];
    sort(shirts, shirts + W + H);
    for (int i = 0; i < W + H; i++) cout << shirts[i] << ' ';
    cout << '\n';
  }
}