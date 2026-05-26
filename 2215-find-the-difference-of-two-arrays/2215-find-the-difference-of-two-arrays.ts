function findDifference(nums1: number[], nums2: number[]): number[][] {
  const num1Set = new Set(nums1);
  const num2Set = new Set(nums2);
  return [
    [...num1Set].filter((n) => !num2Set.has(n)),
    [...num2Set].filter((n) => !num1Set.has(n)),
  ];
}