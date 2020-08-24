package Programmers_42895;

import java.util.HashSet;

class Solution {
    HashSet<Integer>[] s = new HashSet[9];

    public int solution(int N, int number) {
        init(N);
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j < i; j++) {
                int idx1, idx2;
                idx1 = j;
                idx2 = i - j;
                for (int x1 : s[idx1]) {
                    for (int x2 : s[idx2]) {
                        s[i].add(x1 + x2);
                        s[i].add(x1 * x2);
                        s[i].add(x1 - x2);
                        if (x2 != 0)
                            s[i].add(x1 / x2);
                    }
                }
            }
            if (s[i].contains(number))
                return i;
        }

        return -1;
    }

    private void init(int n) {
        int num = n;
        for (int i = 1; i <= 8; i++) {
            s[i] = new HashSet<>();
            s[i].add(num);
            num = num * 10 + n;

        }
    }
}

public class Programmers_42895 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(4, 17));
        System.out.println(s.solution(2, 11));
    }
}
