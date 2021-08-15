import java.io.*
import java.lang.Integer.max
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
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

fun checkAlter(s: String, a: Char, b: Char): Int {
    var result = 0
    var currentChar: Char? = null

    s.forEachIndexed { _, c ->
        if (c == a || c == b) {
            if (
                (currentChar == null) ||
                (c == a && currentChar == b) ||
                (c == b && currentChar == a)
            ) {
                currentChar = c
                result ++
            } else if (c == a && currentChar == a || c == b && currentChar == b)
                return 0
        }
    }

    return result
}

fun alternate(s: String): Int {
    // Write your code here
    var answer = 0
    val alphabets = s.toCharArray().distinct()
    for (i in 0..alphabets.lastIndex)
        for (j in i + 1..alphabets.lastIndex)
            answer = max(answer, checkAlter(s, alphabets[i], alphabets[j]))

    return answer
}

fun main(args: Array<String>) {
    val l = readLine()!!.trim().toInt()
    val s = readLine()!!
    val result = alternate(s)

    println(result)
}
