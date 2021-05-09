import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

// 큐

var N: Int = 0
var queue = mutableListOf<Int>()

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var token = StringTokenizer(br.readLine())
    N = token.nextToken().toInt()

    for (i in 1..N) {
        token = StringTokenizer(br.readLine())
        var oper = token.nextToken()
        when (oper) {
            "push" -> {
                queue.add(token.nextToken().toInt())
            }
            "pop" -> {
                if (queue.isNotEmpty()) {
                    println(queue[0])
                    queue.removeAt(0)
                } else
                    println(-1)
            }
            "size" -> {
                println(queue.size)
            }
            "empty" -> {
                if (queue.isEmpty())
                    println(1)
                else
                    println(0)
            }
            "front" -> {
                if (queue.isNotEmpty())
                    println(queue[0])
                else
                    println(-1)
            }
            "back" -> {
                if (queue.isNotEmpty())
                    println(queue[queue.lastIndex])
                else
                    println(-1)
            }
        }
    }
}