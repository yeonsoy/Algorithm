package baekjoon;

import java.text.SimpleDateFormat;
import java.util.Date;

// 오늘의 날짜는?

public class BOJ16170 {

    public static void main(String[] args) {
        Date today = new Date();
        SimpleDateFormat year = new SimpleDateFormat("yyyy");
        SimpleDateFormat month = new SimpleDateFormat("MM");
        SimpleDateFormat day = new SimpleDateFormat("dd");
         
        System.out.println(year.format(today));
        System.out.println(month.format(today));
        System.out.println(day.format(today));
    }
    
}
