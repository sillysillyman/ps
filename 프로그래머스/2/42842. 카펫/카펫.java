class Solution {

    public int[] solution(int brown, int yellow) {
        int area = brown + yellow;
        int[] answer = {0, 0};

        for (int height = 1; height * height <= area; height++) {
            if (area % height == 0) {
                int width = area / height;

                if (2 * (width + height) - 4 == brown) {
                    answer[0] = width;
                    answer[1] = height;
                    break;
                }
            }
        }
        return answer;
    }
}