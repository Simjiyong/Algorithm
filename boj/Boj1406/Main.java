package Boj1406;

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
        int N;

        char[] input = br.readLine().toCharArray();
        Stack<Character> left, right;
        left = new Stack<>();
        right = new Stack<>();
        for (int i = 0; i < input.length; i++)
            left.push(input[i]);
        N = Integer.parseInt(br.readLine());
        char[] cmd;
        char type;
        for (int i = 0; i < N; i++) {
            cmd = br.readLine().toCharArray();
            type = cmd[0];
            if (type == 'L') {
                if (left.isEmpty())
                    continue;
                right.push(left.pop());
            } else if (type == 'D') {
                if (right.isEmpty())
                    continue;
                left.push(right.pop());
            } else if (type == 'B') {
                if (left.isEmpty())
                    continue;
                left.pop();
            } else {
                left.push(cmd[2]);
            }
        }
        StringBuilder str = new StringBuilder("");
        while (!left.isEmpty()) {
            right.push(left.pop());
        }
        while(!right.isEmpty())
            str.append(right.pop());
        bw.write(str.toString());
        closeIO();
    }
}
