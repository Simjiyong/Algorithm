package Boj6588;

import java.io.*;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static final int MAX_N = 1000000;

    static void setIO() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    static void closeIO() throws IOException {
        br.close();
        bw.flush();
        bw.close();
    }

    static void erathos(int[] num) {
        for (int i = 2; i <= MAX_N; i++)
            num[i] = i;

        for (int i = 2; i * i <= MAX_N; i++) {
            if (num[i] != i)
                continue;
            for (int j = i + i; j <= MAX_N; j += i) {
                num[j] = i;
            }
        }
    }

    static String solve(int n, int[] num) {
        for (int i = 2; i + i <= n; i++) {
            if (num[i] + num[n - i] == n)
                return n + " = " + i + " + " + (n - i);
        }
        return "Goldbach's conjecture is wrong";
    }

    public static void main(String[] args) throws IOException {
        setIO();
        int[] num = new int[MAX_N + 1];
        erathos(num);
        int n;
        while ((n = Integer.parseInt(br.readLine())) != 0) {
            bw.write(solve(n, num) + "\n");
        }
        closeIO();
    }
}

