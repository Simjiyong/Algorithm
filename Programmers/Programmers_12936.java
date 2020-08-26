package Programmers_12936;

import java.util.ArrayList;
import java.util.List;

class Solution {
    final int MAX_N = 20;
    long[] fact = new long[MAX_N + 1];
    List<Integer> order = new ArrayList<>();

    public int[] solution(int n, long k) {
        int[] answer = new int[n];
        init(n);
        int i, idx = 0;
        k--;
        while (k > 0) {
            answer[idx] = order.get((int) (k / fact[n - 1]));
            order.remove((int) (k / fact[n - 1]));
            idx++;
            k %= fact[n - 1];
            n--;
        }
        for(int num : order)
            answer[idx++] = num;

        return answer;
    }

    private void init(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            order.add(i);
        }
    }
}

public class Programmers_12936 {
    public static void main(String[] args) {
        Solution s = new Solution();
        for (int i = 1; i <= 24; i++) {
            for (int res : s.solution(4, i))
                System.out.print(res + " ");
            System.out.println();
            s.order.clear();
        }
    }
}
