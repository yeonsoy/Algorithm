import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

// 숫자 문자열과 영단어

class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0

        val numbers = hashMapOf<String, Int>().apply {
            put("zero", 0)
            put("one", 1)
            put("two", 2)
            put("three", 3)
            put("four", 4)
            put("five", 5)
            put("six", 6)
            put("seven", 7)
            put("eight", 8)
            put("nine", 9)
        }

        var temp: String = ""
        var answer_temp = ""
        for(i in 0..s.lastIndex) {
            if(s[i] >= '0' && s[i] <= '9')
                answer_temp += s[i]
            else {
                temp += s[i]

                if(numbers.getOrDefault(temp, -1) != -1) {
                    answer_temp += numbers[temp].toString()
                    temp = ""
                }
            }
        }



        return answer_temp.toInt()
    }
}