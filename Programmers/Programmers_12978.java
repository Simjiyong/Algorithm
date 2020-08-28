package Programmers_12978;

import java.util.PriorityQueue;

class Pair implements Comparable<Pair> {
    int idx;
    int dist;

    Pair(int idx, int dist) {
        this.idx = idx;
        this.dist = dist;
    }

    @Override
    public int compareTo(Pair p) {
        return dist < p.dist ? 1 : -1;
    }
}

class Solution {
    final int MAX_N = 50;
    final int INF = 987654321;
    int[][] arr = new int[MAX_N + 1][MAX_N + 1];
    int[] dist = new int[MAX_N + 1];
    PriorityQueue<Pair> pq = new PriorityQueue<>();

    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        init(road);
        dijkstra(1, N);
        for (int i = 1; i <= N; i++) {
            if (dist[i] <= K)
                answer++;
        }
        return answer;
    }

    private void dijkstra(int start, int N) {
        dist[start] = 0;
        pq.add(new Pair(start, arr[start][start]));
        Pair cur;
        while (!pq.isEmpty()) {
            cur = pq.poll();
            if (dist[cur.idx] < cur.dist)
                continue;
            for (int i = 1; i <= N; i++) {
                if (dist[i] > arr[cur.idx][i] + cur.dist) {
                    dist[i] = arr[cur.idx][i] + cur.dist;
                    pq.add(new Pair(i, dist[i]));
                }
            }
        }
    }

    private void init(int[][] road) {
        int a, b, c;
        for (int i = 0; i <= MAX_N; i++) {
            for (int j = 0; j <= MAX_N; j++) {
                arr[i][j] = INF;
            }
            arr[i][i] = 0;
            dist[i] = INF;
        }
        for (int i = 0; i < road.length; i++) {
            a = road[i][0];
            b = road[i][1];
            c = road[i][2];
            if (arr[a][b] > c) {
                arr[a][b] = c;
                arr[b][a] = c;
            }
        }
    }
}

public class Programmers_12978 {
    public static void main(String[] args) {

    }
}
