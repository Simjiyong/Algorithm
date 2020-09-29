package Boj11053;

import java.io.*;

public class Main {
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
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] num = new int[N];
        int[] D = new int[N];
        for (int i = 0; i < N; i++)
            num[i] = Integer.parseInt(input[i]);

        int max = -1;
        for (int i = 0; i < N; i++) {
            D[i] = 1;
            for (int j = 0; j < i; j++) {
                if (num[j] < num[i] && D[j] + 1 > D[i]) {
                    D[i] = D[j] + 1;
                }
            }
            max = Math.max(D[i], max);
        }
        bw.write(max + "\n");
        closeIO();
    }
}
