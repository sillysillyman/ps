class Solution {
    
    public int solution(int[] arr) {
        int answer = 1;

        for (int num : arr) {
            answer = lcm(answer, num);
        }
        return answer;
    }

    private int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m % n);
    }

    private int lcm(int m, int n) {
        return m * n / gcd(m, n);
    }
}