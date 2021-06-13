import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

// DFS와 BFS

var N: Int = 0
var M: Int = 0
var V: Int = 0
lateinit var graph:Array<IntArray>
lateinit var visited:BooleanArray

fun useDFS(index: Int, bufferedWriter: BufferedWriter) {
    visited[index] = true
    bufferedWriter.write("$index ")

    for(i in 1 .. N)
        if(graph[index][i] == 1 && visited[i].not()) {
            useDFS(i, bufferedWriter)
        }
}

fun useBFS(index: Int): String {
    val queue: Queue<Int> = LinkedList<Int>()
    queue.offer(index)
    visited[index] = true
    var result: String = ""

    while(!queue.isEmpty()) {
        val front = queue.poll()
        result += "$front "

        for(i in 1 .. N)
            if(graph[front][i] == 1 && visited[i].not()) {
                visited[i] = true
                queue.offer(i)
            }
    }

    return result
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    var token = StringTokenizer(bufferedReader.readLine())
    N = token.nextToken().toInt()
    M = token.nextToken().toInt()
    V = token.nextToken().toInt()

    graph = Array(N + 1) { IntArray(N + 1) {0} }
    visited = BooleanArray(N + 1) {false}
    for(i in 0 until M) {
        token = StringTokenizer(bufferedReader.readLine())
        val a = token.nextToken().toInt()
        val b = token.nextToken().toInt()

        graph[a][b] = 1
        graph[b][a] = 1
    }

    useDFS(V, bufferedWriter)
    bufferedWriter.newLine()
    visited.fill(false)
    bufferedWriter.write("${useBFS(V)}\n")

    bufferedWriter.flush()
    bufferedWriter.close()
}