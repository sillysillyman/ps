import java.util.HashSet;
import java.util.Set;

class Solution {

    public int solution(int[] elements) {
        int size = elements.length;
        int[] extendedElements = new int[2 * size];
        Set<Integer> consecutiveSums = new HashSet<>();

        System.arraycopy(elements, 0, extendedElements, 0, size);
        System.arraycopy(elements, 0, extendedElements, size, size);
        for (int i = 0; i < size; i++) {
            int sum = 0;

            for (int j = 0; j < size; j++) {
                sum += extendedElements[i + j];
                consecutiveSums.add(sum);
            }
        }
        return consecutiveSums.size();
    }
}