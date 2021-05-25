#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 큰 수

bool compare(int a, int b)
{
    string a_str = to_string(a);
    string b_str = to_string(b);
    int a_size = a_str.size();
    int b_size = b_str.size();

    for (int i = 0; i < 4 - a_size; i++)
        a_str += a_str.front();

    for (int i = 0; i < 4 - b_size; i++)
        b_str += b_str.front();

    if (a_str == b_str)
        return a % 10 > b % 10;
    else
        return a_str > b_str;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);

    string res = "";
    for (int i = 0; i < numbers.size(); i++)
        res += to_string(numbers[i]);

    bool isStart = false;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != '0' && !isStart)
            isStart = true;

        if (!isStart) continue;

        answer += res[i];
    }

    if (answer.size() == 0)
        answer = "0";

    return answer;
}