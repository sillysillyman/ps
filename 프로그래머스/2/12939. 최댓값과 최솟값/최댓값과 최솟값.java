import java.util.Arrays;

class Solution {

    public String solution(String s) {
        int[] nums = Arrays.stream(s.split(" ")).mapToInt(Integer::parseInt).toArray();
        int min = Arrays.stream(nums).min().orElse(Integer.MIN_VALUE);
        int max = Arrays.stream(nums).max().orElse(Integer.MAX_VALUE);

        return min + " " + max;
    }
}