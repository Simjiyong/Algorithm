package Programmers_67258;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    HashMap<String, Integer> m = new HashMap<>();
    HashSet<String> s = new HashSet<>();

    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        Collections.addAll(s, gems);
        int l, r, min;
        l = r = 0;
        min = 987654321;

        while (true) {
            if (m.size() == s.size()) {
                if (m.get(gems[l]) == 1) {
                    m.remove(gems[l]);
                } else
                    m.put(gems[l], m.get(gems[l]) - 1);
                l++;
            } else if (r == gems.length)
                break;
            else {
                if (!m.containsKey(gems[r]))
                    m.put(gems[r], 1);
                else
                    m.put(gems[r], m.get(gems[r]) + 1);
                r++;
            }
            if (m.size() == s.size()) {
                if (r - l < min) {
                    min = r - l;
                    answer[0] = l + 1;
                    answer[1] = r;
                }
            }
        }
        return answer;
    }
}

public class Programmers_67258 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new String[]{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"}));
    }
}
