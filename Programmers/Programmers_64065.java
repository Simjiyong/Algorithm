package Programmers_64065;

import java.util.*;

class Solution {
    HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
    int[] num = new int[100001];

    public int[] solution(String s) {
        int[] answer;
        splitNum(s);
        answer = new int[m.size()];
        List<Integer> keySetList = new ArrayList<>(m.keySet());

        Collections.sort(keySetList, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return m.get(o2).compareTo(m.get(o1));
            }
        });

        for(int i=0; i<keySetList.size(); i++)
            answer[i] = keySetList.get(i);

        return answer;
    }

    private void splitNum(String s) {
        s = s.replaceAll("\\{", "").replaceAll("\\}", "");
        String[] string = s.split(",");
        int num;
        for (String n : string) {
            num = Integer.parseInt(n);
            if (m.containsKey(num))
                m.put(num, m.get(num) + 1);
            else
                m.put(num, 1);
        }
    }
}

public class Programmers_64065 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] answer = s.solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
        for(int result : answer){
            System.out.println(result);
        }
    }
}
