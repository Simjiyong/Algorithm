package Boj17298;

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
        String[] input = br.readLine().split(" ");
        int[] num, answer;

        num = new int[N];
        answer = new int[N];
        for (int i = 0; i < num.length; i++)
            num[i] = Integer.parseInt(input[i]);

        Stack<Integer> s = new Stack<>();
        answer[N - 1] = -1;
        s.push(num[N - 1]);
        for (int i = N - 2; i >= 0; i--) {
            if (num[i] < s.peek()) {
                answer[i] = s.peek();
            } else {
                while (!s.isEmpty()) {
                    if (num[i] < s.peek())
                        break;
                    s.pop();
                }
                if (s.isEmpty())
                    answer[i] = -1;
                else
                    answer[i] = s.peek();
            }
            s.push(num[i]);
        }
        for (int i = 0; i < N; i++) {
            bw.write(answer[i] + " ");
        }
        closeIO();
    }
}
