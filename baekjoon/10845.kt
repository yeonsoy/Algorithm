import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

// 큐

var N: Int = 0
var queue = mutableListOf<Int>()

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(bufferedReader.readLine())
    N = token.nextToken().toInt()

    for (i in 1..N) {
        val operation = StringTokenizer(bufferedReader.readLine())
        when (operation.nextToken()) {
            "push" -> {
                queue.add(operation.nextToken().toInt())
            }
            "pop" -> {
                if (queue.isNotEmpty()) {
                    bufferedWriter.write("${queue.first()}\n")
                    queue.removeFirst()
                } else
                    bufferedWriter.write("-1\n")
            }
            "size" -> {
                bufferedWriter.write("${queue.size}\n")
            }
            "empty" -> {
                if (queue.isEmpty())
                    bufferedWriter.write("1\n")
                else
                    bufferedWriter.write("0\n")
            }
            "front" -> {
                if (queue.isNotEmpty())
                    bufferedWriter.write("${queue.first()}\n")
                else
                    bufferedWriter.write("-1\n")
            }
            "back" -> {
                if (queue.isNotEmpty())
                    bufferedWriter.write("${queue.last()}\n")
                else
                    bufferedWriter.write("-1\n")
            }
        }
    }

    bufferedWriter.flush()
    bufferedWriter.close()
}