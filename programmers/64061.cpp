#include <string>
#include <vector>
using namespace std;

// 크레인 인형뽑기 게임

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector <int> res;
    
    for(int i = 0; i<moves.size(); i++) {
        int cur = moves[i] - 1;

        for(int j = 0; j<board[0].size(); j++)
            if(board[j][cur] != 0) {
                if(res.size() < 1)
                    res.push_back(board[j][cur]);
                else
                {
                    if(res[res.size() - 1] == board[j][cur]) {
                        answer+=2;
                        res.pop_back();
                    }
                    else
                        res.push_back(board[j][cur]);
                }
                board[j][cur] = 0;
                break;
            }
    }
    return answer;
}
