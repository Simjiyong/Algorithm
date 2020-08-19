package Programmers_49191;

import java.util.ArrayList;
import java.util.List;

class Solution {
    final static int MAX_N = 100;
    List<Integer>[] winArr = new ArrayList[MAX_N + 1];
    List<Integer>[] loseArr = new ArrayList[MAX_N + 1];
    boolean[] visit = new boolean[MAX_N + 1];

    public int solution(int n, int[][] results) {
        int answer = 0;
        init(n);
        makeArray(results);

        for (int i = 1; i <= n; i++) {
            visit[i] = true;
            dfs(i, winArr);
            dfs(i, loseArr);
            if (check(n))
                answer++;
        }
        return answer;
    }

    private void dfs(int here, List<Integer>[] arr) {
        int next;
        for (int i = 0; i < arr[here].size(); i++) {
            next = arr[here].get(i);
            if (visit[next])
                continue;
            visit[next] = true;
            dfs(next, arr);
        }
    }

    private boolean check(int n) {
        boolean flag = true;
        for (int i = 1; i <= n; i++) {
            if (!visit[i])
                flag = false;
            visit[i] = false;
        }
        return flag;
    }

    private void init(int n) {
        for (int i = 1; i <= n; i++) {
            winArr[i] = new ArrayList<>();
            loseArr[i] = new ArrayList<>();
        }
    }

    private void makeArray(int[][] results) {
        int winIdx, loseIdx;
        for (int[] result : results) {
            winIdx = result[0];
            loseIdx = result[1];
            winArr[winIdx].add(loseIdx);
            loseArr[loseIdx].add(winIdx);
        }
    }
}

public class Programmers_49191 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(5, new int[][]{{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}));
    }
}
