import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Solution {

    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> countMap = new HashMap<>();

        for (int size : tangerine) {
            countMap.put(size, countMap.getOrDefault(size, 0) + 1);
        }

        ArrayList<Integer> counts = new ArrayList<>(countMap.values());
        counts.sort(Collections.reverseOrder());

        for (int count : counts) {
            k -= count;
            answer++;
            if (k <= 0) {
                break;
            }
        }

        return answer;
    }
}