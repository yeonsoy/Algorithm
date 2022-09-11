#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최댓값과 최솟값

vector<string> split(string s, char div)
{
    vector<string> result;

    string temp = "";
    for (const char& c : s)
    {
        if (c == div) {
            result.push_back(temp);
            temp.clear();
        }
        else
            temp += c;
    }

    result.push_back(temp);
    return result;
}

string solution(string s) {
    vector<string> numbers = split(s, ' ');
    vector<int> result;

    for (const string& number : numbers)
        result.push_back(stoi(number));

    sort(result.begin(), result.end());

    return to_string(result.front()) + " " + to_string(result.back());
}