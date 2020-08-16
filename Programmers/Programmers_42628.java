package Programmers_42628;

import java.util.*;

class Solution {
    List<Integer> q = new ArrayList<>();

    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        for (String oper : operations) {
            switch (oper.charAt(0)) {
                case 'I':
                    insertQueue(oper.substring(2));
                    break;
                case 'D':
                    deleteQueue(oper.charAt(2));
                    break;
            }
        }
        if(q.isEmpty())
            return new int[]{0, 0};
        Collections.sort(q);
        answer[1] = q.get(0);
        answer[0] = q.get(q.size()-1);
        return answer;
    }

    private void deleteQueue(char c) {
        if (q.isEmpty()) return;

        Collections.sort(q);
        if (c == '-') {
            q.remove(0);
        } else {
            q.remove(q.size() - 1);
        }
    }

    private void insertQueue(String substring) {
        Integer num = Integer.parseInt(substring);
        q.add(num);
    }
}

public class Programmers_42628 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] answer = s.solution(new String[]{"I 16", "D 1"});
        System.out.println(answer[0] + "," + answer[1]);


        answer = s.solution(new String[]{"I 7","I 5", "D -1"});
        System.out.println(answer[0] + "," + answer[1]);
    }
}
