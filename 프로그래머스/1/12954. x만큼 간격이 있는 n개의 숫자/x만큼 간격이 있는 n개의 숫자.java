import java.util.stream.IntStream;

class Solution {

    public long[] solution(int x, int n) {
        return IntStream.range(0, n).mapToLong(i -> (long) x * (i + 1)).toArray();
    }
}