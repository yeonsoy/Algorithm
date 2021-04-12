import java.util.*

// 10부제

fun main() {
    val sc = Scanner(System.`in`)
    val N: Int = sc.nextInt()
    var answer: Int = 0
    for(i in 1 .. 5) {
        val num = sc.nextInt()
        if(num % 10 == N)
            answer++
    }

    print(answer)
}