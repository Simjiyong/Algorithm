package Boj9012;

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
    static String check(String str){
        int open = 0;
        char c;
        for(int i=0; i<str.length(); i++) {
            c = str.charAt(i);
            if(c == '(')
                open++;
            else {
                if(open <= 0)
                    return "NO";
                else
                    open--;
            }
        }
        if(open > 0)
            return "NO";
        return "YES";
    }
    public static void main(String[] args) throws IOException{
        setIO();
        int T = Integer.parseInt(br.readLine());
        for(int tc = 0; tc<T; tc++){
            bw.write(check(br.readLine()) + '\n');
        }
        closeIO();
    }
}
