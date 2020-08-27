package Programmers_12952;

class Solution {
    int[] col = new int[13];
    int answer = 0;

    public int solution(int n) {
        for (int i = 1; i <= n; i++) {
            col[1] = i;
            dfs(1, n);
        }
        return answer;
    }

    private void dfs(int cnt, int n) {
        if (cnt == n) {
            answer++;
            return;
        }

        for (int i = 1; i <= n; i++) { // i열
            if (!isPossible(cnt + 1, i)) // cnt행 i열
                continue;
            col[cnt + 1] = i;
            dfs(cnt + 1, n);
        }
    }

    private boolean isPossible(int c, int r) {
        for (int i = 1; i < c; i++) {
            if (col[i] == r)
                return false;
            if (Math.abs(col[i] - r) == Math.abs(i - c))
                return false;
        }
        return true;
    }
}

public class Programmers_12952 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(12));
    }
}
