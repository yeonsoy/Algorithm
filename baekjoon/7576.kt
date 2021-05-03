import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

// 토마토

var N: Int = 0
var M: Int = 0
lateinit var tomato: Array<IntArray>

fun isEnd(): Boolean {
    for (i in 0 until N)
        for (j in 0 until M)
            if (tomato[i][j] == 0)
                return false

    return true
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var token = StringTokenizer(br.readLine())
    M = token.nextToken().toInt()
    N = token.nextToken().toInt()
    tomato = Array(N) { IntArray(M) }
    val que: Queue<Pair<Int, Int>> = LinkedList()

    for (i in 0 until N) {
        token = StringTokenizer(br.readLine())
        for (j in 0 until M) {
            tomato[i][j] = token.nextToken().toInt()
            if (tomato[i][j] == 1)
                que.offer(Pair(i, j))
        }
    }

    val dir: Array<Pair<Int, Int>> = arrayOf(Pair(0, 1), Pair(1, 0), Pair(0, -1), Pair(-1, 0))
    var isPossible = false
    var answer = 0

    if (!isEnd()) {
        while (!que.isEmpty()) {
            val front = que.poll()
            for (d in dir) {
                val r = front.first + d.first
                val c = front.second + d.second

                if (r < 0 || r >= N || c < 0 || c >= M) continue
                if (tomato[r][c] == -1) continue
                if (tomato[r][c] == 0) {
                    tomato[r][c] = tomato[front.first][front.second] + 1

                    if (answer < tomato[r][c])
                        answer = tomato[r][c]

                    que.offer(Pair(r, c))
                }
            }
        }

        if (isEnd()) {
            answer--
            isPossible = true
        }
    } else {
        answer = 0
        isPossible = true
    }

    if (!isPossible)
        answer = -1

    print(answer)
}