import java.util.Arrays;

class Solution {

    public int solution(int[] citations) {
        Arrays.sort(citations);

        int left = 0, right = citations.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (citations[citations.length - mid - 1] >= mid + 1) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}