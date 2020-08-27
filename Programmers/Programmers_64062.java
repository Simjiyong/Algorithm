package Programmers_64062;

import java.util.Comparator;
import java.util.TreeSet;

class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        answer = binarySearch(1, 200000000, stones, k);
        return answer;
    }

    private int binarySearch(int left, int right, int[] stones, int k) {
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (isPossible(mid, stones, k))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    private boolean isPossible(int n, int[] stones, int k) {
        int cnt = 0;
        for (int i = 0; i < stones.length; i++) {
            if (n <= stones[i])
                cnt = 0;
            else
                cnt++;
            if (cnt == k)
                return false;
        }
        return true;
    }
}

public class Programmers_64062 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[]{2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3));
        System.out.println(s.solution(new int[]{1, 1, 1, 1, 1, 5, 1, 1, 2, 1}, 3));
    }
}
