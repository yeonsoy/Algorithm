import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

// 팰린드롬 만들기

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(bufferedReader.readLine())
    val name: String = token.nextToken().toString()
    val alphabet: IntArray = IntArray(26) { 0 }
    var middleIndex: Int = -1

    fun isPossible(name: CharArray): Boolean {
        var oddCount = 0

        for (i in name.indices)
            alphabet[name[i].toInt().minus('A'.toInt())]++

        for (i in 0 until 26)
            if (alphabet[i] % 2 == 1) {
                oddCount++
                middleIndex = i
            }

        if (name.size % 2 == 1 && oddCount == 1)
            return true

        if (name.size % 2 == 0 && oddCount == 0)
            return true

        return false
    }


    if (isPossible(name.toCharArray())) {
        var half: String = ""

        for (i in 0 until 26) {
            for (j in 0 until alphabet[i] / 2)
                half += "${i.plus('A'.toInt()).toChar()}"
        }
        bufferedWriter.write(half)

        if (middleIndex != -1)
            bufferedWriter.write("${middleIndex.plus('A'.toInt()).toChar()}")

        bufferedWriter.write(half.reversed())
    } else {
        bufferedWriter.write("I'm Sorry Hansoo")
    }

    bufferedWriter.flush()
    bufferedWriter.close()


}