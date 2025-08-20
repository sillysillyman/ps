function isPalindrome(x: number): boolean {
  const s = x.toString();
  return s === s.split('').reverse().join('');
};