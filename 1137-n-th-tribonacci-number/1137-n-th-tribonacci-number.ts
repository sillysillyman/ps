function tribonacci(n: number): number {
  const dp = [0, 1, 1, ...Array(35).fill(0)];
  dp.forEach((_, i) => i > 2 && (dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]));
  return dp[n];
}