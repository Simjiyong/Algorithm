package Boj11727;

import java.io.*;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static int[] D = new int[1001];
    final static int MOD = 10007;

    static void setIO() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    static void closeIO() throws IOException {
        br.close();
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        setIO();
        D[1] = 1;
        D[2] = 3;
        int N = Integer.parseInt(br.readLine());
        for (int i = 3; i <= N; i++) {
            D[i] = (D[i - 1] + D[i - 2] * 2) % MOD;
        }
        bw.write(D[N] + "\n");
        closeIO();
    }
}
