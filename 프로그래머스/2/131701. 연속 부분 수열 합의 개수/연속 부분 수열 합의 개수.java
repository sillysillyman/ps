import java.util.HashSet;
import java.util.Set;

class Solution {

    public int solution(int[] elements) {
        int n = elements.length;
        int[] extendedElements = new int[2 * n];
        Set<Integer> consecutiveSums = new HashSet<>();

        System.arraycopy(elements, 0, extendedElements, 0, n);
        System.arraycopy(elements, 0, extendedElements, n, n);
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                sum += extendedElements[i + j];
                consecutiveSums.add(sum);
            }
        }
        return consecutiveSums.size();
    }
}