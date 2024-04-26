using namespace std;

long long solution(int price, int money, int count) {
  if (long long answer = (long long)price * (count * (1 + count) / 2) - money;
      answer > 0)
    return answer;
  else
    return 0;
}