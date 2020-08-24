package Programmers_43105;

class Solution {
    public int solution(int[][] triangle) {
        for (int i = triangle.length - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += Math.max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
}

public class Programmers_43105 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[][]{{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}}));
    }
}
