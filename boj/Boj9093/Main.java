package Boj9093;


import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bf = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        String line[];
        StringBuilder sb = new StringBuilder("");
        for (int tc = 0; tc < T; tc++) {
            line = br.readLine().split(" ");
            for (int i = 0; i < line.length; i++) {
                for (int j = line[i].length() - 1; j >= 0; j--) {
                    sb.append((line[i].charAt(j)));
                }
                sb.append(" ");
            }
            sb.append('\n');
        }
        bf.write(sb.toString());

        br.close();
        bf.flush();
        bf.close();
    }
}
