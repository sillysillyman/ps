function minCostClimbingStairs(cost: number[]): number {
  let [a, b] = [cost[0], cost[1]];
  for (let i = 2; i < cost.length; i++) {
    [a, b] = [b, Math.min(a, b) + cost[i]];
  }
  return Math.min(a, b);
}