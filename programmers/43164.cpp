#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

// 여행경로

using namespace std;
bool isUsed[10001];
vector <string> answer;
vector <vector<string>> result;

void solve(vector<vector<string>> tickets, string str, int sum) {
    if (sum == (int)tickets.size()) {
        result.push_back(answer);
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (!isUsed[i] && str == tickets[i][0]) {
            isUsed[i] = true;
            answer.push_back(tickets[i][1]);
            solve(tickets, tickets[i][1], sum + 1);
            answer.pop_back();
            isUsed[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++) {

        if (tickets[i][0] == "ICN")
        {
            isUsed[i] = true;
            answer.push_back(tickets[i][0]);
            answer.push_back(tickets[i][1]);
            solve(tickets, tickets[i][1], 1);
            if (result.size() > 0)
                break;
        }

        answer.clear();
        memset(isUsed, false, sizeof(isUsed));
    }

    sort(result.begin(), result.end());

    return result[0];
}