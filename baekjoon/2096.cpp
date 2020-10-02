#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 내려가기

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;
struct score {
    int sc[3];
};
vector <score> scores;
int answer_min = 2e9, answer_max;

int main() {
    
    fastio();
    cin >> N;
    
    scores.resize(N);
    
    for(int i = 0; i<N; i++)
        cin >> scores[i].sc[0] >> scores[i].sc[1] >> scores[i].sc[2];
    
    score cur = scores[0];
    score temp;
    
    for(int i = 1; i<N; i++) {
        temp.sc[0] = max(cur.sc[0], cur.sc[1]) + scores[i].sc[0];
        temp.sc[1] = max(cur.sc[0], max(cur.sc[1], cur.sc[2])) + scores[i].sc[1];
        temp.sc[2] = max(cur.sc[1], cur.sc[2]) + scores[i].sc[2];
        
        cur = temp;
    }
    
    cout << max(cur.sc[0], max(cur.sc[1], cur.sc[2])) << " ";
    
    cur = scores[0];
    
    for(int i = 1; i<N; i++) {
        temp.sc[0] = min(cur.sc[0], cur.sc[1]) + scores[i].sc[0];
        temp.sc[1] = min(cur.sc[0], min(cur.sc[1], cur.sc[2])) + scores[i].sc[1];
        temp.sc[2] = min(cur.sc[1], cur.sc[2]) + scores[i].sc[2];
        
        cur = temp;
    }
    
    cout << min(cur.sc[0], min(cur.sc[1], cur.sc[2])) << endl;
    
    return 0;
}
