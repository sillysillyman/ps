#include <cstdio>

static const int BUFSZ = 1 << 20;
static unsigned char buf[BUFSZ];
static int idx = 0, sz = 0;

inline int readInt() {
  int x = 0;
  unsigned char c;
  do {
    if (idx >= sz) {
      sz = fread(buf, 1, BUFSZ, stdin);
      idx = 0;
    }
    c = buf[idx++];
  } while (c <= ' ');
  do {
    x = x * 10 + (c - '0');
    if (idx >= sz) {
      sz = fread(buf, 1, BUFSZ, stdin);
      idx = 0;
    }
    c = buf[idx++];
  } while (c > ' ');
  return x;
}

int main() {
  int N = readInt();
  int p = 0, n = 0;
  for (int i = 0; i < N; i++) {
    int c = readInt();
    n += (c >= p);
    p = c;
  }
  printf("%d\n", n);
}