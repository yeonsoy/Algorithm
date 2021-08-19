import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

fun superReducedString(s: String): String {
    // Write your code here
    var current = s
    while (true) {
        var temp = ""
        var i = 0
        while (true) {
            if(i > current.lastIndex)
                break

            if (i == current.lastIndex) {
                temp += current.last()
                break
            }

            if (current[i] == current[i + 1]) {
                i+=2
                continue
            }

            temp += current[i]

            i++
        }

        if (current == temp)
            break

        current = temp
    }

    if (current.isEmpty())
        current = "Empty String"

    return current
}

fun main(args: Array<String>) {
    val s = readLine()!!

    val result = superReducedString(s)

    println(result)
}
