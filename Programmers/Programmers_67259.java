package Programmers_67259;

import java.util.LinkedList;
import java.util.Queue;

class Road {
    int y;
    int x;
    int cost;
    int dir;

    Road(int y, int x, int cost, int dir) {
        this.y = y;
        this.x = x;
        this.cost = cost;
        this.dir = dir;
    }
}

class Solution {
    final int MAX_N = 25;
    final int INF = 987654321;
    int[][][] cost = new int[MAX_N][MAX_N][4];
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1}; // URDL
    Queue<Road> q = new LinkedList<>();

    public int solution(int[][] board) {
        int answer = 987654321;
        int N = board.length;
        init(N);
        for (int dir = 0; dir < 4; dir++) {
            int ny, nx;
            ny = dy[dir];
            nx = dx[dir];
            if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
                continue;
            if (board[ny][nx] == 1)
                continue;
            cost[ny][nx][dir] = 100;
            q.add(new Road(ny, nx, 100, dir));
        }

        int ny, nx;
        Road cur;
        while (!q.isEmpty()) {
            cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                ny = cur.y + dy[dir];
                nx = cur.x + dx[dir];
                if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
                    continue;
                if (board[ny][nx] == 1)
                    continue;
                int tmp = cur.dir % 2 == dir % 2 ? 100 : 600;
                if (ny == N - 1 && nx == N - 1) {
                    answer = Math.min(answer, cur.cost + tmp);
                    continue;
                }
                if (cost[ny][nx][dir] <= cur.cost + tmp)
                    continue;
                cost[ny][nx][dir] = cur.cost + tmp;
                q.add(new Road(ny, nx, cur.cost + tmp, dir));
            }
        }

        return answer;
    }

    private void init(int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int dir = 0; dir < 4; dir++) {
                    cost[i][j][dir] = INF;
                }
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            cost[0][0][dir] = 0;
        }
    }
}

public class Programmers_67259 {

}
