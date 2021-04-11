import java.util.*

// 세금

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    val N: Int = sc.nextInt()

    val price1: Int = (N * 0.78).toInt()
    val price2: Int = (N * 0.8 + N * 0.2 * 0.78).toInt()
    
    println("$price1 $price2")
}