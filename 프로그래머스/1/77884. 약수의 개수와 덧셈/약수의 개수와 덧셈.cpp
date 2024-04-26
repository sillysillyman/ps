using namespace std;

int solution(int left, int right) {
  int answer = 0;

  for (int i = left; i <= right; i++) {
    int cnt = 0;

    for (int j = 1; j * j <= i; j++) {
      if (j * j == i)
        ++cnt;
      else if (!(j % i))
        cnt += 2;
    }
    if (cnt % 2)
      answer -= i;
    else
      answer += i;
  }
  return answer;
}