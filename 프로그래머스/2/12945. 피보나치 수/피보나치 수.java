class Solution {

    private static final int MOD = 1_234_567;

    public int solution(int n) {
        if (n == 0) {
            return 0;
        }

        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i++) {
            int next = (prev + curr) % MOD;

            prev = curr;
            curr = next;
        }
        return curr;
    }
}