package Programmers_42885;

import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int l, r;
        l = 0;
        r = people.length - 1;
        while (l < r) {
            if(people[l] + people[r] <= limit)
                l++;
            r--;
            answer++;
        }
        if (l == r)
            answer++;

        return answer;
    }
}

public class Programmers_42885 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[]{70, 50, 80, 50}, 100));
    }
}
