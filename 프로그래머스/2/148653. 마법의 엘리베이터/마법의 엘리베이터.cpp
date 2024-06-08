int solution(int storey) {
  int answer = 0;

  while (storey > 0) {
    int curr = storey % 10;

    if (curr > 5) {
      answer += 10 - curr;
      storey += 10;
    } else if (curr < 5)
      answer += curr;
    else {
      answer += 5;
      if ((storey / 10) % 10 >= 5) storey += 10;
    }
    storey /= 10;
  }
  return answer;
}