package Programmers_64064;

import java.util.Arrays;
import java.util.HashSet;

class Solution {

    boolean[] visit = new boolean[8];
    HashSet<String> s = new HashSet<>();

    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        for (int i = 0; i < user_id.length; i++) {
            visit[i] = true;
            dfs(Integer.toString(i), user_id, banned_id);
            visit[i] = false;
        }
        return s.size();
    }

    private void dfs(String cur, String[] user_id, String[] banned_id) {
        if (cur.length() == banned_id.length) {
            if (possibleBan(cur, user_id, banned_id)) {
                char[] str = cur.toCharArray();
                Arrays.sort(str);
                s.add(Arrays.toString(str));
            }
            return;
        }
        for (int i = 0; i < user_id.length; i++) {
            if (visit[i])
                continue;
            visit[i] = true;
            dfs(cur + i, user_id, banned_id);
            visit[i] = false;
        }
    }

    private boolean possibleBan(String cur, String[] user_id, String[] banned_id) {
        for (int i = 0; i < cur.length(); i++) {
            int idx = cur.charAt(i) - '0';
            if (!check(user_id[idx], banned_id[i]))
                return false;
        }
        return true;
    }

    private boolean check(String userId, String banId) {
        if (userId.length() != banId.length())
            return false;
        for (int i = 0; i < userId.length(); i++) {
            if (banId.charAt(i) != '*' && userId.charAt(i) != banId.charAt(i))
                return false;
        }
        return true;
    }
}

public class Programmers_64064 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        String[] ban = {"fr*d*", "abc1**"};
        System.out.println(s.solution(user_id, ban));
    }
}
