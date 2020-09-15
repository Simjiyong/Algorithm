package Boj1874;

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
        int[] num = new int[N];
        for(int i=0; i<N; i++){
            num[i] = Integer.parseInt(br.readLine());
        }
        StringBuilder answer = new StringBuilder("");
        Stack<Integer> s = new Stack<>();
        int idx = 0;
        for(int i=1; i<=N; i++){
            s.add(i);
            answer.append("+\n");
            while(!s.isEmpty() && s.peek() == num[idx]) {
                s.pop();
                answer.append("-\n");
                idx++;
            }
        }
        if(!s.isEmpty())
            bw.write("NO\n");
        else
            bw.write(answer.toString());
        closeIO();
    }
}
