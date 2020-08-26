package Programmers_12927;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

//class Solution {
//    Integer[] sortedWorks;
//
//    public long solution(int n, int[] works) {
//        long answer = 0;
//        sortedWorks = Arrays.stream(works).boxed().toArray(Integer[]::new);
//        Arrays.sort(sortedWorks, Comparator.reverseOrder());
//        int i, s, e, diff;
//        i = s = e = 0;
//        while (i < sortedWorks.length) {
//            s = lowerBound(0, sortedWorks.length, sortedWorks[i]);
//            e = upperBound(0, sortedWorks.length, sortedWorks[i]);
//            if (e == sortedWorks.length) {
//                if (n >= sortedWorks[s] * (e - s))
//                    return 0;
//                break;
//            }
//            diff = sortedWorks[s] - sortedWorks[e];
//
//            if (n < diff * (e - s))
//                break;
//
//            n -= diff * (e - s);
//            for (int j = s; j < e; j++)
//                sortedWorks[j] = sortedWorks[e];
//            i = e;
//        }
//
//        int cnt = 0;
//        while (n >= e - s) {
//            n -= e - s;
//            cnt++;
//        }
//        for (int j = s; j < e; j++) {
//            sortedWorks[j] -= cnt;
//        }
//        for (int j = 0; j < n; j++) {
//            sortedWorks[s]--;
//            s++;
//        }
//
//        for (int num : sortedWorks) {
//            answer += num * num;
//        }
//        return answer;
//    }
//
//    private int upperBound(int start, int end, int target) {
//        int mid;
//        while (start < end) {
//            mid = (start + end) / 2;
//            if (sortedWorks[mid] >= target)
//                start = mid + 1;
//            else
//                end = mid;
//        }
//        return end;
//    }
//
//    private int lowerBound(int start, int end, int target) {
//        int mid;
//        while (start < end) {
//            mid = (start + end) / 2;
//            if (sortedWorks[mid] > target)
//                start = mid + 1;
//            else
//                end = mid;
//        }
//        return end;
//    }
//}

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int work : works) {
            pq.add(work);
        }

        while (n > 0) {
            if (pq.peek() == 0)
                return 0;
            pq.add(pq.poll() - 1);
            n--;
        }

        for (int time : pq) {
            answer += time * time;
        }
        return answer;
    }
}

public class Programmers_12927 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(4, new int[]{4, 3, 3}));
        System.out.println(s.solution(1, new int[]{2, 1, 2}));
        System.out.println(s.solution(3, new int[]{1, 1}));
    }
}
