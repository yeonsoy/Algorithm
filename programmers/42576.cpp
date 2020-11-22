#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 완주하지 못한 선수

string solution(vector<string> participant, vector<string> completion) {

    string answer = "";

    unordered_map <string, int> m;

    for (string& p : participant)
        m[p]++;

    for (string& c : completion)
        m[c]--;

    for (auto& res : m)
        if (res.second == 1)
        {
            answer = res.first;
            break;
        }

    return answer;
}