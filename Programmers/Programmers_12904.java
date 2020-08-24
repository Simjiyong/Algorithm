package Programmers_12904;

class Solution {
    final static int MAX_LEN = 2500;
    boolean[][] D = new boolean[MAX_LEN + 1][MAX_LEN + 1];

    public int solution(String s) {
        int answer = 1, len;
        len = s.length();
        for (int i = 0; i < len; i++) {
            D[1][i] = true;
        }

        for (int i = 0; i < len - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                D[2][i] = true;
                answer = 2;
            }
        }

        for (int j = 3; j <= len; j++) {
            for (int i = 0; i < len - j + 1; i++) {
                if (s.charAt(i) == s.charAt(i + j - 1) && D[j - 2][i + 1]) {
                    D[j][i] = true;
                    answer = j;
                }
            }
        }

        return answer;
    }
}

public class Programmers_12904 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution("a"));
        s = new Solution();
        System.out.println(s.solution("abccba"));
    }
}
