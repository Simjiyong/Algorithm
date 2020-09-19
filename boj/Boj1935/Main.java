package Boj1935;

import java.io.*;
import java.util.Stack;

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
        double[] num = new double[26];
        char[] input = br.readLine().toCharArray();
        for (int i = 0; i < N; i++) {
            num[i] = Double.parseDouble(br.readLine());
        }

        Stack<Double> s = new Stack<>();
        double n1, n2;
        for (char c : input) {
            switch (c) {
                case '+':
                    n2 = s.pop();
                    n1 = s.pop();
                    s.push(n1 + n2);
                    break;
                case '-':
                    n2 = s.pop();
                    n1 = s.pop();
                    s.push(n1 - n2);
                    break;
                case '*':
                    n2 = s.pop();
                    n1 = s.pop();
                    s.push(n1 * n2);
                    break;
                case '/':
                    n2 = s.pop();
                    n1 = s.pop();
                    s.push(n1 / n2);
                    break;
                default:
                    s.push(num[c - 'A']);
                    break;
            }
        }
        System.out.printf("%.2f\n", s.peek());
        closeIO();
    }
}
