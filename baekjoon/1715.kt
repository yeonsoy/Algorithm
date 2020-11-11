import java.util.*

// 카드 정렬하기

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    val N = sc.nextInt()
    val cards = PriorityQueue<Int>()
    for(i in 0 until N)
        cards.add(sc.nextInt())
    var answer = 0
    if(cards.size != 1) {
        while (cards.size != 1) {
            val a = cards.poll()
            val b = cards.poll()
            if (cards.size >= 1)
                answer += a + b

            cards.add(a + b)
        }

        println(answer + cards.poll())
    }
    else
        println(answer)
}