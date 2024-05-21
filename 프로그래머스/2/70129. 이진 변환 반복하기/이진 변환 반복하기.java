class Solution {

    public int[] solution(String s) {
        int[] answer = {0, 0};

        while (!s.equals("1")) {
            int countOnes = 0;
            int length = s.length();

            for (int i = 0; i < length; i++) {
                if (s.charAt(i) == '1') {
                    ++countOnes;
                }
            }
            answer[1] += length - countOnes;
            s = Integer.toBinaryString(countOnes);
            answer[0]++;
        }
        return answer;
    }
}