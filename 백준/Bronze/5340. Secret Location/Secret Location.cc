#include <cstdio>
#include <cstring>

int main() {
  int arr[6];
  char str[181];

  for (int len, i = 0; i < 6; i++) {
    scanf(" %[^\n]%*c", str);
    len = strlen(str);
    if (str[len - 1] == ' ') str[len--] = '\0';
    arr[i] = len;
  }
  printf("Latitude %d:%d:%d\nLongitude %d:%d:%d\n", arr[0], arr[1], arr[2],
         arr[3], arr[4], arr[5]);
}