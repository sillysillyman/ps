class Solution {

    private static final int MOD = 1_234_567;

    public long solution(int n) {
        long prev = 1;
        long curr = 1;

        for (int i = 2; i <= n; i++) {
            long next = (prev + curr) % MOD;

            prev = curr;
            curr = next;
        }
        return curr;
    }
}