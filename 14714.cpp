#include <iostream>
using namespace std;

// 홍삼 게임 (Easy)

int N;
int A, B;
int DA, DB;
int answer;
int isUsedA[501][1000];
int isUsedB[501][1000];

int main() {
    
    cin >> N >> A >> B >> DA >> DB;
    
    A--; B--;
    
    isUsedA[A][0] = true;
    isUsedB[B][0] = true;
    
    int cur = 0;
    
    while(true) {
       
        if(answer > 1000) break;
        
        answer++;
        for (int i = 0; i < N; i++) {
            if(isUsedA[i][cur]) {
                int la = (i - DA);
                int ra = (i + DA) % N;
                
                if(la < 0)
                    la += N;
                
                if(isUsedB[la][cur] || isUsedB[ra][cur]) {
                    cout << answer << endl;
                    exit(0);
                }else {
                    isUsedA[la][cur + 1] = true;
                    isUsedA[ra][cur + 1] = true;
                }
            }
        }
        
        answer++;
        for (int i = 0; i < N; i++) {
            if(isUsedB[i][cur]) {
                int lb = (i - DB);
                int rb = (i + DB) % N;
                
                if(lb < 0)
                    lb += N;
                if(isUsedA[lb][cur + 1] || isUsedA[rb][cur + 1]) {
                    cout << answer << endl;
                    exit(0);
                }else {
                    isUsedB[lb][cur + 1] = true;
                    isUsedB[rb][cur + 1] = true;
                }
            }
        }
        cur++;
    }
    
    cout << "Evil Galazy" << endl;
    
    return 0;
}
