import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.abs

// 도영이가 만든 맛있는 음식

var N: Int = 0
var answer: Int = Int.MAX_VALUE
val dishes = ArrayList<Dish>()
lateinit var isUsed: BooleanArray

fun checkDish(count: Int, index: Int, sour: Int, bitter: Int) {
    if(count > 0) {
        answer = min(answer, abs(sour - bitter))
    }

    if(count < dishes.size) {
        for (i in index..dishes.lastIndex) {
            if(!isUsed[i]) {
                isUsed[i] = true
                checkDish(count + 1, i,sour * dishes[i].S, bitter + dishes[i].B)
                isUsed[i] = false
            }
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var token = StringTokenizer(br.readLine())
    N = token.nextToken().toInt()
    isUsed = BooleanArray(N) {false}

    for (i in 1..N) {
        token = StringTokenizer(br.readLine())
        dishes.add(Dish(S = token.nextToken().toInt(), B = token.nextToken().toInt()))
    }

    checkDish(0, 0,1, 0)
    print(answer)
}

data class Dish (
        val S: Int = 0, // 신맛
        val B: Int = 0 // 쓴맛
)