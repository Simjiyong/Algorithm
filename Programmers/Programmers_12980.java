package Programmers_12980;

class Solution {
    public int solution(int n) {
        int ans = 0;
        while (n > 0){
            if(n%2 == 1) {
                n--;
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
}


public class Programmers_12980 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(5000));
    }
}
