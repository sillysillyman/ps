function mergeAlternately(word1: string, word2: string): string {
  return Array.from(
    { length: Math.max(word1.length, word2.length) },
    (_, i) => (word1[i] ?? '') + (word2[i] ?? ''),
  ).join('');
}