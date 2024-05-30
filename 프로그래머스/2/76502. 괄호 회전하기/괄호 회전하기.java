import java.util.Stack;

public class Solution {

    private static boolean hasMatchingParentheses(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.peek();
                if (ch == ')' && top == '(') {
                    stack.pop();
                } else if (ch == '}' && top == '{') {
                    stack.pop();
                } else if (ch == ']' && top == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public int solution(String s) {
        int answer = 0;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (hasMatchingParentheses(s.substring(i) + s.substring(0, i))) {
                ++answer;
            }
        }
        return answer;
    }
}