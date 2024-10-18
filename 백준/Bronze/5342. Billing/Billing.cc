#include <cstdio>
#include <cstring>

int main() {
  float bill = 0;
  char supply[10];

  while (scanf(" %s", supply) && strcmp(supply, "EOI")) {
    if (supply[0] == 'P') {
      if (supply[1] == 'a')
        bill += 57.99;
      else if (supply[1] == 'r')
        bill += 120.5;
      else if (supply[1] == 'l')
        bill += 31.25;
    } else if (supply[0] == 'B')
      bill += 22.5;
    else if (supply[0] == 'C')
      bill += 10.95;
    else if (supply[0] == 'N')
      bill += 11.2;
    else if (supply[0] == 'I')
      bill += 66.95;
  }
  printf("$%.2f", bill);
}