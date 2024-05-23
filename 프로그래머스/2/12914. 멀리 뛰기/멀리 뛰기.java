class Solution {

    private static final int MOD = 1_234_567;
    private static final long[] dp = new long[2_001];

    public long solution(int n) {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
}