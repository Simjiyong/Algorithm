package Boj17299;

import java.io.*;
import java.util.HashMap;
import java.util.Stack;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static void setIO(){
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
        HashMap<Integer, Integer> m = new HashMap<>();
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] num = new int[N];
        for(int i=0; i<N; i++){
            num[i] = Integer.parseInt(input[i]);
            if(m.containsKey(num[i]))
                m.put(num[i], m.get(num[i]) + 1);
            else
                m.put(num[i], 1);
        }

        int[] answer = new int[N];
        Stack<Integer> s = new Stack<>();
        s.push(num[N-1]);
        answer[N-1] = -1;

        int cur;
        for(int i=N-2; i>=0; i--){
            cur = m.get(num[i]);
            if(cur < m.get(s.peek())){
                answer[i] = s.peek();
            } else {
                while(!s.isEmpty()){
                    if(cur < m.get(s.peek()))
                        break;
                    s.pop();
                }
                if(s.isEmpty())
                    answer[i] = -1;
                else
                    answer[i] = s.peek();
            }
            s.push(num[i]);
        }

        for(int i=0; i<N; i++){
            bw.write(answer[i] + " ");
        }
        closeIO();
    }
}
