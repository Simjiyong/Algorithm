package Boj10799;

import java.io.*;

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
        char[] input = br.readLine().toCharArray();
        int openCnt = 1;
        int answer = 0;
        for(int i=1; i<input.length; i++){
            if(input[i] == '('){
                openCnt++;
            }
            else{
                openCnt--;
                if(input[i-1] == '('){
                    answer += openCnt;
                } else{
                    answer += 1;
                }
            }
        }
        bw.write(answer + "\n");
        closeIO();
    }
}
