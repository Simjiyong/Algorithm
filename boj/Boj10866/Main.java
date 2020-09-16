package Boj10866;

import java.io.*;

class MyDeque {
    static private final int MAX_SIZE = 10000;
    private int[] arr;
    private int front;
    private int back;
    private int size;

    MyDeque() {
        arr = new int[MAX_SIZE];
        front = 0;
        back = 0;
        size = 0;
    }

    void push_back(int n) {
        arr[back] = n;
        back = (back + 1) % MAX_SIZE;
        size++;
    }

    void push_front(int n) {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        arr[front] = n;
        size++;
    }

    int pop_front() {
        if (size == 0)
            return -1;
        int res = front();
        front = (front + 1) % MAX_SIZE;
        size--;
        return res;
    }

    int pop_back() {
        if (size == 0)
            return -1;
        int res = back();
        back = (back - 1 + MAX_SIZE) % MAX_SIZE;
        size--;
        return res;
    }

    int size() {
        return size;
    }

    int empty() {
        if (size == 0)
            return 1;
        return 0;
    }

    int front() {
        if (size == 0)
            return -1;
        return arr[front];
    }

    int back() {
        if (size == 0)
            return -1;
        int end = (back - 1 + MAX_SIZE) % MAX_SIZE;
        return arr[end];
    }

}

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
        MyDeque dq = new MyDeque();
        String[] input;
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            switch (input[0]) {
                case "push_front":
                    dq.push_front(Integer.parseInt(input[1]));
                    break;
                case "push_back":
                    dq.push_back(Integer.parseInt(input[1]));
                    break;
                case "pop_front":
                    bw.write(dq.pop_front() + "\n");
                    break;
                case "pop_back":
                    bw.write(dq.pop_back() + "\n");
                    break;
                case "size":
                    bw.write(dq.size() + "\n");
                    break;
                case "empty":
                    bw.write(dq.empty() + "\n");
                    break;
                case "front":
                    bw.write(dq.front() + "\n");
                    break;
                case "back":
                    bw.write(dq.back() + "\n");
                    break;
            }
        }
        closeIO();
    }
}
