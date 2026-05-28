function minCostClimbingStairs(cost: number[]): number {
  const dp = [cost[0], cost[1], ...Array(cost.length - 2)];
  for (let i = 2; i < dp.length; i++) {
    dp[i] = Math.min(dp[i - 2], dp[i - 1]) + cost[i];
  }
  return Math.min(dp.at(-2), dp.at(-1));
}