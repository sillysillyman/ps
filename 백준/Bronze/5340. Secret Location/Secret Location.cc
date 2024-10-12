#include <cstdio>
#include <cstring>

int main() {
  int arr[6];
  char str[181];

  for (int i = 0; i < 6; i++) {
    scanf(" %[^\n]", str);
    arr[i] = strlen(str) - (str[strlen(str) - 1] == ' ');
  }
  printf("Latitude %d:%d:%d\nLongitude %d:%d:%d\n", arr[0], arr[1], arr[2],
         arr[3], arr[4], arr[5]);
}