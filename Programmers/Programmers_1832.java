package Programmers_1832;

class Solution {
    final int MOD = 20170805;
    final int MAX_N = 500;
    final int MAX_M = 500;
    final int LEFT = 0;
    final int DOWN = 1;
    int[][][] D = new int[MAX_M + 1][MAX_N + 1][2];

    public int solution(int m, int n, int[][] cityMap) {
        int answer = 0;
        if (m == 1 && n == 1)
            return 1;
        init(m, n, cityMap);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (cityMap[i][j] == 1) {
                    D[i][j][LEFT] = D[i][j][DOWN] = 0;
                    continue;
                }
                D[i][j][LEFT] = D[i][j - 1][LEFT];
                if (cityMap[i][j - 1] != 2)
                    D[i][j][LEFT] += D[i][j - 1][DOWN];

                D[i][j][DOWN] = D[i - 1][j][DOWN];
                if (cityMap[i - 1][j] != 2)
                    D[i][j][DOWN] += D[i - 1][j][LEFT];

                D[i][j][LEFT] %= MOD;
                D[i][j][DOWN] %= MOD;
            }
        }
        answer = (D[m - 1][n - 1][LEFT] + D[m - 1][n - 1][DOWN]) % MOD;
        return answer;
    }

    private void init(int m, int n, int[][] cityMap) {
        D[0][0][DOWN] = 1;
        D[0][0][LEFT] = 1;
        for (int i = 1; i < m; i++) {
            if (cityMap[i][0] == 1)
                D[i][0][DOWN] = 0;
            else
                D[i][0][DOWN] = D[i - 1][0][DOWN];
        }

        for (int i = 1; i < n; i++) {
            if (cityMap[0][i] == 1)
                D[0][i][LEFT] = 0;
            else
                D[0][i][LEFT] = D[0][i - 1][LEFT];
        }
    }
}

public class Programmers_1832 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(3, 3,
                new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}));
        System.out.println(s.solution(3, 6,
                new int[][]{{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}));
    }
}
