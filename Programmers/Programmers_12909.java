package Programmers_12909;

class Solution {
    boolean solution(String s) {
        int open = 0;
        char c;
        for (int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            if (c == '(')
                open++;
            else if (open > 0)
                open--;
            else
                return false;
        }
        return open == 0;
    }
}

public class Programmers_12909 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution("()()"));
    }
}
