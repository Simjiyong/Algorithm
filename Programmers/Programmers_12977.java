package Programmers_12977;

class Solution {
    final int MAX_N = 3000;
    int[] a = new int[MAX_N];
    boolean[] visit = new boolean[50];
    int answer = 0;

    public int solution(int[] nums) {
        eratos();
        for (int i = 0; i < nums.length; i++) {
            visit[i] = true;
            pickNum(i, nums[i], 1, nums);
            visit[i] = false;
        }
        return answer;
    }

    private void pickNum(int here, int sum, int cnt, int[] nums) {
        if (cnt == 3) {
            if (a[sum] == sum)
                answer++;
            return;
        }
        for (int i = here + 1; i < nums.length; i++) {
            if (visit[i]) continue;
            visit[i] = true;
            pickNum(i, sum + nums[i], cnt + 1, nums);
            visit[i] = false;
        }
    }

    private void eratos() {
        for (int i = 2; i < MAX_N; i++) {
            a[i] = i;
        }
        for (int i = 2; i < MAX_N; i++) {
            if (a[i] != i) continue;
            if ((long) i * i > MAX_N) break;
            for (int j = i * i; j < MAX_N; j += i) {
                if (a[j] == j) a[j] = i;
            }
        }
    }
}

public class Programmers_12977 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[]{1,2,3,4}));
    }
}
