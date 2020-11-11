import java.util.*

// 잃어버린 괄호

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    val str: String = sc.nextLine()

    var temp = StringBuffer("")
    var numbers = Stack<Int>()
    var opers = Stack<Char>()

    opers.add('+')

    var flag = false
    for(ch in str)
    {
        if(ch in '0'..'9') {
            temp.append(ch)
        }
        else
        {
            if(!opers.isEmpty())
            {
                var op = opers.pop()
                if(op == '-' && ch == '+')
                {
                    numbers.add(Integer.parseInt(temp.toString()))
                    opers.add(op)
                    opers.add('-')
                    temp = StringBuffer("")
                    continue
                }
                else
                    opers.add(op)
            }
            opers.add(ch)
            numbers.add(Integer.parseInt(temp.toString()))
            temp = StringBuffer("")
        }
    }

    numbers.add(Integer.parseInt(temp.toString()))
    var answer = 0

    while(numbers.size != 0)
    {
        var num = numbers.pop()
        var oper = opers.pop()
        if(oper == '-')
            answer += -num
        else
            answer += num
    }

    println(answer)
}