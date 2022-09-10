#include <string>
#include <vector>

using namespace std;

// 하노이의 탑

void towerOfHanoi(int n, int from, int to, int via, vector<vector<int>>& answer) {
    if (n == 1)
        answer.push_back({ from, to });
    else {
        towerOfHanoi(n - 1, from, via, to, answer);
        answer.push_back({ from, to });
        towerOfHanoi(n - 1, via, to, from, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    towerOfHanoi(n, 1, 3, 2, answer);
    return answer;
}