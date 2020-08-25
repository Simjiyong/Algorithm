package Programmers_1836;

import java.util.*;

class Point {
    int y;
    int x;

    Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Line {
    Point p;
    int dir;
    int cnt;

    Line(Point p, int dir, int cnt) {
        this.p = p;
        this.dir = dir;
        this.cnt = cnt;
    }
}

class Solution {
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    List<Point>[] tiles = new ArrayList[26];
    TreeSet<Integer> s = new TreeSet<>();
    char[][] map;

    public String solution(int m, int n, String[] board) {
        StringBuilder answer = new StringBuilder();
        init(m, n, board);
        boolean flag = false;
        while (!s.isEmpty()) {
            flag = true;
            for (int idx : s) {
                if (checkRoute(idx, m, n)) {
                    updateBoard(idx);
                    s.remove(idx);
                    answer.append((char) (idx + 'A'));
                    flag = false;
                    break;
                }
            }
            if (flag)
                return "IMPOSSIBLE";
        }
        return answer.toString();
    }

    private void updateBoard(int idx) {
        Point p;
        for (int i = 0; i < 2; i++) {
            p = tiles[idx].get(i);
            map[p.y][p.x] = '.';
        }
    }

    private boolean checkRoute(int idx, int m, int n) {
        Point sp, ep;
        sp = tiles[idx].get(0);
        ep = tiles[idx].get(1);
        boolean[][][] visit = new boolean[m][n][4];
        for (int dir = 0; dir < 4; dir++)
            visit[sp.y][sp.x][dir] = true;
        Queue<Line> q = new LinkedList<>();
        int ny, nx;
        for (int dir = 0; dir < 4; dir++) {
            ny = sp.y + dy[dir];
            nx = sp.x + dx[dir];
            if (ny < 0 || nx < 0 || ny > m - 1 || nx > n - 1)
                continue;
            if (ny == ep.y && nx == ep.x)
                return true;
            if (visit[ny][nx][dir])
                continue;
            if (map[ny][nx] != '.')
                continue;
            visit[ny][nx][dir] = true;
            q.add(new Line(new Point(ny, nx), dir, 0));
        }

        while (!q.isEmpty()) {
            Line cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                ny = cur.p.y + dy[dir];
                nx = cur.p.x + dx[dir];
                if (cur.dir % 2 != dir % 2 && cur.cnt == 1)
                    continue;
                if (ny < 0 || nx < 0 || ny >= m || nx >= n)
                    continue;
                if (ny == ep.y && nx == ep.x)
                    return true;
                if (visit[ny][nx][dir])
                    continue;
                if (map[ny][nx] != '.')
                    continue;
                visit[ny][nx][dir] = true;
                q.add(new Line(new Point(ny, nx), dir,
                        cur.dir % 2 == dir % 2 ? cur.cnt : cur.cnt + 1));
            }
        }
        return false;
    }

    private void init(int m, int n, String[] board) {
        map = new char[m][n];
        for (int i = 0; i < 26; i++) {
            tiles[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            map[i] = board[i].toCharArray();
            for (int j = 0; j < n; j++) {
                char c = map[i][j];
                if (c == '.' || c == '*')
                    continue;
                s.add(c - 'A');
                tiles[c - 'A'].add(new Point(i, j));
            }
        }
    }
}


public class Programmers_1836 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] board = {"DBA", "C*A", "CDB"};

        board = new String[]{"AZD*", "....", "....", ".AZD"};

        System.out.println(s.solution(4, 4, board));
    }
}
