package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 킹, 퀸, 룩, 비숍, 나이트, 폰

public class BOJ3003 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int [] nums = new int [6];
        int [] chess = {1, 1, 2, 2, 2, 8};
        
        for(int i = 0; i<6; i++)
            nums[i] = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i<6; i++)
            System.out.print(chess[i] - nums[i] + " ");
        
    }
    
}
