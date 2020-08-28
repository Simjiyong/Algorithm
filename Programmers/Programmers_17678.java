package Programmers_17678;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.PriorityQueue;

class Solution {
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        int min;
        for (String tmp : timetable) {
            String[] time = tmp.split(":");
            min = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
            pq.add(min);
        }

        int shuttle = 9 * 60;
        int cnt, cur, max = 0;
        while (n > 0) {
            cnt = cur = 0;
            while (cnt < m && !pq.isEmpty()) {
                if (pq.peek() > shuttle)
                    break;
                cur = pq.poll();
                cnt++;
            }
            if (cnt == m) //꽉 찼을때;
                max = cur - 1;
            else //꽉 안찼을때
                max = shuttle;
            n--;
            shuttle += t;
        }
        SimpleDateFormat df = new SimpleDateFormat("HH:mm");
        df.format(new Date(max * 1000L));
        answer = df.format(new Date((max - 9*60) * 60000L));
        return answer;
    }
}

public class Programmers_17678 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(1,1,5,
                new String[]{"08:00", "08:01", "08:02", "08:03"}));
    }
}
