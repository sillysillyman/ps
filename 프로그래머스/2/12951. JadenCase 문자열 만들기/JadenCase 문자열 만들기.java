class Solution {

    public String solution(String s) {
        StringBuilder answer = new StringBuilder();
        boolean capitalizeNext = true;

        for (char ch : s.toCharArray()) {
            if (ch == ' ') {
                answer.append(ch);
                capitalizeNext = true;
            } else if (capitalizeNext) {
                answer.append(Character.toUpperCase(ch));
                capitalizeNext = false;
            } else {
                answer.append(Character.toLowerCase(ch));
            }
        }
        return answer.toString();
    }
}