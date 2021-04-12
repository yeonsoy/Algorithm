import java.util.*

// Darius님 한타 안 함?

fun main() {
    val sc = Scanner(System.`in`)
    val str: String = sc.nextLine()

    var kda: List<String> = str.split('/')
    val K = kda[0].toInt()
    val D = kda[1].toInt()
    val A = kda[2].toInt()

    if(K + A < D || D == 0)
        print("hasu")
    else
        print("gosu")
}