package Boj3954;

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
        char[] input = br.readLine().toCharArray();
        boolean tag = false;
        Stack<Character> s = new Stack<>();
        for (char c : input) {
            switch (c) {
                case '<':
                    while (!s.isEmpty())
                        bw.write(s.pop());
                    tag = true;
                    bw.write(c);
                    break;
                case '>':
                    tag = false;
                    bw.write(c);
                    break;
                case ' ':
                    while (!s.isEmpty())
                        bw.write(s.pop());
                    bw.write(c);
                    break;
                default:
                    if (tag)
                        bw.write(c);
                    else {
                        s.push(c);
                    }
            }
        }
        while (!s.isEmpty())
            bw.write(s.pop());
        closeIO();
    }
}
