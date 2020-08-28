package Programmers_12979;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int start, end;
        start = 1;
        for (int i = 0; i < stations.length; i++) {
            end = stations[i] - w;
            if (start < end)
                answer += find(start, end, w);
            start = stations[i] + w + 1;
        }
        if (start <= n)
            answer += find(start, n + 1, w);
        return answer;
    }

    private int find(int start, int end, int w) { // start <=  < end
        int res, range = 2 * w + 1;
        res = (end - start) / range;
        if ((end - start) % range != 0)
            res++;
        return res;
    }
}

public class Programmers_12979 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(1, new int[]{1}, 1));
    }
}
