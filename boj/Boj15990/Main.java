package Boj15990;

import java.io.*;

public class Main {
    final static int MOD = 1000000009;
    final static int MAX_N = 100000;
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
        int T = Integer.parseInt(br.readLine());
        int num;
        int[][] D = new int[MAX_N + 1][4];
        D[1][1] = D[2][2] = D[3][3] = 1;
        D[3][1] = D[3][2] = 1;
        for (int i = 4; i <= MAX_N; i++) {
            D[i][1] = (D[i - 1][2] + D[i - 1][3]) % MOD;
            D[i][2] = (D[i - 2][1] + D[i - 2][3]) % MOD;
            D[i][3] = (D[i - 3][1] + D[i - 3][2]) % MOD;
        }

        for (int tc = 0; tc < T; tc++) {
            num = Integer.parseInt(br.readLine());
            bw.write(((D[num][1] + D[num][2]) % MOD + D[num][3]) % MOD + "\n");
        }
        closeIO();
    }
}

