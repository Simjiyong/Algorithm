package Programmers_1835;

class Solution {
    char[] name = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int[] order = new int[26];
    int answer = 0;
    public int solution(int n, String[] data) {
        for (int i = 0; i < name.length; i++) {
            int idx = name[i] - 'A';
            order[idx] = 1;
            makeLine(Character.toString(name[i]), data);
            order[idx] = 0;
        }
        return answer;
    }

    void makeLine(String line, String[] data) {
        if (line.length() == 8) {
            if(checkData(line, data))
                answer++;
            return;
        }
        int idx;
        for (int i = 0; i < name.length; i++) {
            idx = name[i] - 'A';
            if (order[idx] != 0)
                continue;
            order[idx] = line.length() + 1;
            makeLine(line + name[i], data);
            order[idx] = 0;
        }
    }

    Boolean checkData(String line, String[] data) {
        int dist, idx1, idx2;
        for (int i = 0; i < data.length; i++) {
            idx1 = data[i].charAt(0) - 'A';
            idx2 = data[i].charAt(2) - 'A';
            dist = data[i].charAt(4) - '0';
            dist++;
            switch (data[i].charAt(3)) {
                case '=':
                    if(Math.abs(order[idx1] - order[idx2]) != dist)
                        return false;
                    break;
                case '<':
                    if(Math.abs(order[idx1] - order[idx2]) >= dist)
                        return false;
                    break;
                case '>':
                    if(Math.abs(order[idx1] - order[idx2]) <= dist)
                        return false;
                    break;
            }
        }
        return true;
    }
}

public class Programmers_1835 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(2, new String[]{"N~F=0", "R~T>2"}));
    }
}
