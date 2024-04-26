#include <iostream>

using namespace std;

string solution(string phone_number) {
  return phone_number.replace(0, phone_number.length() - 4,
                              phone_number.length() - 4, '*');
}