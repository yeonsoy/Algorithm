#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이진 변환 반복하기

string removeZero(string s) {
    string result = "";

    for (const char& ch : s)
        if (ch != '0')
            result += ch;
    return result;
}

string toBinary(int n) {
    string result = "";
    while (n) {
        result += to_string(n % 2);
        n /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s != "1") {
        string removedZero = removeZero(s);
        string binary = toBinary(removedZero.size());
        answer[1] += s.size() - removedZero.size();
        answer[0] ++;
        s = binary;
    }

    return answer;
}