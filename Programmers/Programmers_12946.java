package Programmers_12946;

import java.util.ArrayList;
import java.util.List;

class Solution {
    List<Integer[]> res = new ArrayList<>();
    public int[][] solution(int n) {
        int[][] answer;
        hanoi(n, 1, 3, 2);

        System.out.println(res.size());
        answer = new int[res.size()][2];
        for(int i=0; i<res.size(); i++){
            answer[i][0] = res.get(i)[0];
            answer[i][1] = res.get(i)[1];
        }
        return answer;
    }

    private void hanoi(int n, int from, int to, int sub) {
        if (n == 1) {
            res.add(new Integer[]{from, to});
            return;
        }

        hanoi(n - 1, from, sub, to);
        res.add(new Integer[]{from, to});
        hanoi(n - 1, sub, to, from);
    }
}

public class Programmers_12946 {
    public static void main(String[] args) {
        Solution s = new Solution();
        for (int[] res : s.solution(15)) {
            System.out.println(res[0] + " " + res[1]);
        }
    }
}
