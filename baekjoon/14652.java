package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 나는 행복합니다~

public class BOJ16170 {

    public static void main(String[] args) {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int NUM = Integer.parseInt(st.nextToken());
        
        System.out.println(NUM / M + " " + NUM % M);
    }
    
}
