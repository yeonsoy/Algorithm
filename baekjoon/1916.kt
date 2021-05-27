import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

// 최소비용 구하기

var N: Int = 0
var M: Int = 0

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    var token = StringTokenizer(bufferedReader.readLine())
    N = token.nextToken().toInt()
    token = StringTokenizer(bufferedReader.readLine())
    M = token.nextToken().toInt()

    val city = Array<ArrayList<Pair<Int, Int>>>(N) { ArrayList() }
    val distance: IntArray = IntArray(N)

    var lambda = { a: Int, b: Int ->
        when {
            a < b -> 1
            a > b -> -1
            else -> 0
        }
    }

    val queue: PriorityQueue<Pair<Int, Int>> = PriorityQueue(
        Comparator<Pair<Int, Int>> { a, b ->
            when {
                a.first != b.first -> lambda(a.first, b.first)
                else -> lambda(a.second, b.second)
            }
        }
    )

    distance.fill(Int.MAX_VALUE)

    for (i in 1..M) {
        token = StringTokenizer(bufferedReader.readLine())
        val startCity = token.nextToken().toInt().minus(1)
        val endCity = token.nextToken().toInt().minus(1)
        val cost = token.nextToken().toInt()

        city[startCity].add(endCity to cost)
    }

    token = StringTokenizer(bufferedReader.readLine())
    val startCity: Int = token.nextToken().toInt().minus(1)
    val endCity: Int = token.nextToken().toInt().minus(1)

    // 시작점과 시작점의 거리는 0
    distance[startCity] = 0
    queue.add(startCity to distance[startCity])

    while (!queue.isEmpty()) {
        val front = queue.poll()
        val currentCity = front.first
        val currentCost = front.second

        // 미리 구해둔 비용보다 현재 가는 경로가 비용이 더 크다면
        if (currentCost > distance[currentCity])
            continue

        for (i in 0..city[currentCity].lastIndex) {
            val nextCity = city[currentCity][i].first
            val nextCost = city[currentCity][i].second

            // startCity->nextCity로 가는 경로 비용 > startCity->currentCity->nextCity로 가는 비용인 경우 갱신
            if (distance[nextCity] > distance[currentCity] + nextCost) {
                distance[nextCity] = distance[currentCity] + nextCost
                queue.add(nextCity to distance[nextCity])
            }
        }

    }

    bufferedWriter.write("${distance[endCity]}")

    bufferedWriter.flush()
    bufferedWriter.close()
}