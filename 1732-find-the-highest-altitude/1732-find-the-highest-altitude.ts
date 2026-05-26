function largestAltitude(gain: number[]): number {
  let altitude = 0;
  return Math.max(0, ...gain.map((diff) => (altitude += diff)));
}