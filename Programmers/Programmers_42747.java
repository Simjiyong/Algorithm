package Programmers_42747;

import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);

        int idx, len;
        len = citations.length;
        for (int h = 1000; h >= 0; h--) {
            idx = lower_bound(h, citations);
            if (len - idx >= h)
                return h;
        }
        return answer;
    }

    int lower_bound(int value, int[] citations) {
        int mid, low, high;
        low = 0;
        high = citations.length;
        while (low < high) {
            mid = (low + high) / 2;
            if (value <= citations[mid])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
}

public class Programmers_42747 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[]{3, 0, 6, 1, 5}));
    }
}
