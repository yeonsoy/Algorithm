import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

// 부족한 금액 계산하기

class Solution {
    fun solution(price: Int, money: Int, count: Int): Long {
        var answer: Long = 0

        var current = 0
        for (i in 0 until count) {
            current += price
            answer += current
        }

        answer -= money

        if (answer < 0)
            answer = 0

        return answer
    }
}