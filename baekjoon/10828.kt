import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

// 스택

var N: Int = 0
var stack = mutableListOf<Int>()

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var token = StringTokenizer(br.readLine())
    N = token.nextToken().toInt()

    for (i in 1..N) {
        token = StringTokenizer(br.readLine())
        var oper = token.nextToken()
        when (oper) {
            "push" -> {
                stack.add(token.nextToken().toInt())
            }
            "pop" -> {
                if (stack.isNotEmpty()) {
                    println(stack[stack.lastIndex])
                    stack.removeAt(stack.lastIndex)
                } else
                    println(-1)
            }
            "size" -> {
                println(stack.size)
            }
            "empty" -> {
                if (stack.isEmpty())
                    println(1)
                else
                    println(0)
            }
            "top" -> {
                if (stack.isNotEmpty())
                    println(stack[stack.lastIndex])
                else
                    println(-1)
            }
        }
    }
}