function uniqueOccurrences(arr: number[]): boolean {
  const counts = arr.reduce(
    (m, n) => m.set(n, (m.get(n) ?? 0) + 1),
    new Map<number, number>(),
  );
  return new Set(counts.values()).size === counts.size;
}