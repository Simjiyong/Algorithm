package Boj10844;

import java.io.*;

public class Main {
    final static int MOD = 1000000000;
    final static int MAX_N = 100;
    static BufferedReader br;
    static BufferedWriter bw;

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
        int[][] D = new int[MAX_N + 1][10];
        for (int i = 1; i < 10; i++)
            D[1][i] = 1;
        int N = Integer.parseInt(br.readLine());
        for (int i = 2; i <= N; i++) {
            D[i][0] = D[i - 1][1];
            for (int j = 1; j < 9; j++)
                D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % MOD;
            D[i][9] = D[i - 1][8];
        }
        int answer = 0;
        for (int i = 0; i < 10; i++) {
            answer = (answer + D[N][i]) % MOD;
        }
        bw.write(answer + "\n");
        closeIO();
    }
}
