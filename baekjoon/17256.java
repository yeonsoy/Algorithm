package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 달달함이 넘쳐흘러

public class BOJ17256 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        cake a = new cake(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        
        st = new StringTokenizer(br.readLine());
        cake c = new cake(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        
        System.out.print(c.x - a.z);
        System.out.print(" ");
        System.out.print(c.y / a.y);
        System.out.print(" ");
        System.out.print(c.z - a.x);
    }
    
    static class cake {
        public int x;
        public int y;
        public int z;
        
        cake(int xx, int yy, int zz) {
            x = xx;
            y = yy;
            z = zz;
        }
    }
    
}
