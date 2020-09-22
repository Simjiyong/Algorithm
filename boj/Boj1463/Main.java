package Boj1463;

import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static int[] D = new int[1000000 + 1];
    static final int INF = 987654321;

    static void setIO() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    static void closeIO() throws IOException {
        br.close();
        bw.flush();
        bw.close();
    }

    static int solve(int N) {
        if (D[N] != INF)
            return D[N];

        if (N % 3 == 0)
            D[N] = Math.min(D[N], solve(N / 3) + 1);
        if (N % 2 == 0)
            D[N] = Math.min(D[N], solve(N / 2) + 1);
        D[N] = Math.min(D[N], solve(N - 1) + 1);

        return D[N];
    }

    public static void main(String[] args) throws IOException {
        setIO();
        Arrays.fill(D, INF);
        D[1] = 0;
        int N = Integer.parseInt(br.readLine());
        for (int i = 2; i <= N; i++) {
            if (i % 3 == 0)
                D[i] = Math.min(D[i], D[i / 3] + 1);
            if (i % 2 == 0)
                D[i] = Math.min(D[i], D[i / 2] + 1);
            D[i] = Math.min(D[i], D[i - 1] + 1);
        }
        bw.write(D[N] + "\n");
        //bw.write(solve(N) + "\n");
        closeIO();
    }
}
