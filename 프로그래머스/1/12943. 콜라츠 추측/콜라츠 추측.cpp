using namespace std;

int solution(int num) {
  int answer = 0;
  long long tmp = num;

  while (tmp != 1) {
    if (answer++ > 500) return -1;
    if (tmp % 2)
      tmp = 3 * tmp + 1;
    else
      tmp /= 2;
  }
  return answer;
}