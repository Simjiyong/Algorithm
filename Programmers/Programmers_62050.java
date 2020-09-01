package Programmers_62050;


import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Point {
    int y;
    int x;

    Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Ladder implements Comparable<Ladder> {
    int height;
    int idx;

    Ladder(int height, int idx) {
        this.height = height;
        this.idx = idx;
    }

    @Override
    public int compareTo(Ladder l) {
        return height - l.height;
    }
}

class Solution {
    final int MAX_N = 300;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    int[][] group = new int[MAX_N][MAX_N];
    int N, cnt = 1;
    boolean[] visit;
    PriorityQueue<Ladder> pq = new PriorityQueue<>();
    Queue<Point> q = new LinkedList<>();

    public int solution(int[][] land, int height) {
        int answer = 0;
        N = land.length;
        makeGroup(land, height);
        answer = mst(1, land);
        return answer;
    }

    private int mst(int here, int[][] land) {
        visit = new boolean[cnt + 1];
        visit[here] = true;
        makeAdj(here, land);
        int answer = 0, edge = 0;
        Ladder tmp;
        while (!pq.isEmpty()) {
            tmp = pq.poll();
            if (visit[tmp.idx])
                continue;
            visit[tmp.idx] = true;
            answer += tmp.height;
            edge++;
            if (edge == cnt - 1)
                return answer;
            makeAdj(tmp.idx, land);

        }
        return 0;
    }

    private void makeAdj(int here, int[][] land) {
        int cur, next, ny, nx;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cur = group[i][j];
                if (cur != here)
                    continue;
                for (int dir = 0; dir < 4; dir++) {
                    ny = i + dy[dir];
                    nx = j + dx[dir];
                    if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
                        continue;
                    next = group[ny][nx];
                    if (visit[next])
                        continue;
                    pq.add(new Ladder(Math.abs(land[i][j] - land[ny][nx]), next));
                }
            }
        }
    }

    private void makeGroup(int[][] land, int height) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (group[i][j] > 0)
                    continue;
                group[i][j] = cnt;
                q.add(new Point(i, j));
                bfs(land, height);
                cnt++;
            }
        }
        cnt--;
    }

    private void bfs(int[][] land, int height) {
        int ny, nx;
        Point cur;
        while (!q.isEmpty()) {
            cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                ny = cur.y + dy[dir];
                nx = cur.x + dx[dir];
                if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
                    continue;
                if (group[ny][nx] != 0)
                    continue;
                if (Math.abs(land[cur.y][cur.x] - land[ny][nx]) > height)
                    continue;
                group[ny][nx] = cnt;
                q.add(new Point(ny, nx));
            }
        }
    }
}

public class Programmers_62050 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] land = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
        //int[][] land = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
        System.out.println(s.solution(land, 3));

    }
}

