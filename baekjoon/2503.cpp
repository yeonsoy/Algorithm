#include <iostream>
#include <vector>
using namespace std;

// 숫자 야구

struct game {
    int num[3];
    int strike;
    int ball;
};

int N;
vector<game> baseball;
int answer;
bool check(game q, int pivot[3]) {
    
    int ball_count = 0;
    int strike_count = 0;
    
    for(int i = 0; i<3; i++) {
        if(q.num[i] == pivot[i])
            strike_count++;
        
        for(int j = 0; j<3; j++) {
 
            if(i == j) continue;
            
            if(q.num[i] == pivot[j])
                ball_count++;
        }
    }
    
    if(q.ball == ball_count && q.strike == strike_count)
        return true;
    else
        return false;
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        game g;
        int num;
        cin >> num >> g.strike >> g.ball;
        g.num[0] = num / 100;
        g.num[1] = (num % 100) / 10;
        g.num[2] = (num % 10);
        
        baseball.push_back(g);
    }
    
    for(int i = 100; i<1000; i++) {
        int pivot[3] = { i / 100, (i % 100) / 10, (i % 10)};
        if(pivot[0] == pivot[1]) continue; // 서로 다른 세 가지 숫자
        if(pivot[1] == pivot[2]) continue;
        if(pivot[0] == pivot[2]) continue;
        if(pivot[0] == 0 || pivot[1] == 0 || pivot[2] == 0) continue; // 자연수로 구성된 수이므로 0 제외
 
        bool isAnswer = true;
        
        for(int j = 0; j<baseball.size(); j++)
            if(!check(baseball[j], pivot))
            {
                isAnswer = false;
                break;
            }
        
        if(isAnswer)
            answer++;
    }
    
    cout << answer;
    
    return 0;
}
