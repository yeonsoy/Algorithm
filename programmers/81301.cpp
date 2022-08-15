#include <string>
#include <vector>

using namespace std;

// 숫자 문자열과 영단어

int checkNumber(string str)
{
    if (str == "zero")
        return 0;
    else if (str == "one")
        return 1;
    else if (str == "two")
        return 2;
    else if (str == "three")
        return 3;
    else if (str == "four")
        return 4;
    else if (str == "five")
        return 5;
    else if (str == "six")
        return 6;
    else if (str == "seven")
        return 7;
    else if (str == "eight")
        return 8;
    else if (str == "nine")
        return 9;
    else
        return -1;
}

int solution(string s) {
    int answer = 0;
    std::vector<int> numbers;

    string temp = "";
    int num = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
            num = checkNumber(temp);
            if (num != -1)
            {
                numbers.push_back(num);
                temp = "";
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
            numbers.push_back(s[i] - '0');
    }

    int tens = 1;
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        answer += numbers[i] * tens;
        tens *= 10;
    }

    return answer;
}