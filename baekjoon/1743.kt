import java.util.*

// 음식물 피하기

class Point (var r: Int = 0, var c: Int = 0)
var dir = arrayOf(Point(0, 1), Point(1, 0), Point(-1, 0), Point(0, -1))
var N: Int = 0
var M: Int = 0

fun main(args: Array<String>)
{

    var sc = Scanner(System.`in`)
    N = sc.nextInt()
    M = sc.nextInt()
    var K = sc.nextInt()

    var food:Array<IntArray> = Array(N) { IntArray(M) }
    var indexed:Array<IntArray> = Array(N) { IntArray(M) }

    var a: Int = 0
    var b: Int = 0

    for(i in 1 .. K)
    {
        a = sc.nextInt()
        b = sc.nextInt()

        food[a - 1][b - 1] = 1
    }

    var idx = 0
    var answer = 0
    for(i in 0 until N)
        for(j in 0 until M)
            if(indexed[i][j] == 0 && food[i][j] == 1)
            {
                idx++
                answer = max(bfs(i, j, indexed, food, idx), answer)
            }

    println(answer)
}

fun max(a: Int, b: Int) : Int
{
    if(a > b) return a
    else return b
}

fun bfs(i: Int, j: Int, indexed: Array<IntArray>, food: Array<IntArray>, idx: Int) : Int
{
    var res = 0
    var que: Queue<Point> = LinkedList<Point>()
    que.add(Point(i, j))
    indexed[i][j] = idx
    res++

    while(!que.isEmpty())
    {
        var front = que.poll()
        for(i in 0 until 4)
        {
            var rr = dir[i].r + front.r
            var cc = dir[i].c + front.c

            if(rr < 0 || rr >= N || cc < 0 || cc >= M)
                continue

            if(food[rr][cc] == 1 && indexed[rr][cc] == 0)
            {
                que.add(Point(rr,cc))
                indexed[rr][cc] = idx
                res++
            }
        }

    }

    return res
}