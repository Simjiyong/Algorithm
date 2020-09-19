package Boj1918;

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
        Stack<Character> s = new Stack<>();
        for (char c : input) {
            if ('A' <= c && c <= 'Z') {
                bw.write(c);
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while(s.peek() != '(')
                    bw.write(s.pop());
                s.pop();
            } else if (c == '*' || c == '/') {
                while(!s.isEmpty()) {
                    if (s.peek() == '+' || s.peek() == '-' || s.peek() == '(')
                        break;
                    bw.write(s.pop());
                }
                s.push(c);
            } else {
                while(!s.isEmpty()) {
                    if(s.peek() == '(')
                        break;
                    bw.write(s.pop());
                }
                s.push(c);
            }
        }
        while(!s.isEmpty())
            bw.write(s.pop());
        closeIO();
    }
}
