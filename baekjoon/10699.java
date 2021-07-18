package baekjoon;

import java.text.SimpleDateFormat;
import java.util.Date;

// 오늘 날짜

public class BOJ10699 {

    public static void main(String[] args) {
        Date today = new Date();
        SimpleDateFormat year = new SimpleDateFormat("yyyy");
        SimpleDateFormat month = new SimpleDateFormat("MM");
        SimpleDateFormat day = new SimpleDateFormat("dd");

        System.out.println(year.format(today) + "-" + month.format(today) + "-" + day.format(today));
    }

}
