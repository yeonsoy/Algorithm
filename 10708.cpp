#include <iostream>
#include <vector>
using namespace std;

// 크리스마스 파티

int N, M;
int score[101];
int result[101][101];
vector <int> targets;

int main() {
    cin >> N >> M;
    
    for(int i = 0; i<M; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }
    
    for(int i = 0; i<M; i++)
        for(int j = 0; j<N; j++)
            cin >> result[i][j];
    
    for(int i = 0; i<M; i++) {
        int target_score = 0;
        for(int j = 0; j<N; j++)
        {
            if(targets[i] == result[i][j]) // 타겟을 맞췄으면
                score[j]++;
            else
                target_score++;
        }
        score[targets[i] - 1] += target_score; // 틀린 사람만큼 타겟에 더하기
    }
    
    for(int i = 0; i<N; i++)
        cout << score[i] << endl;
    
    return 0;
}
