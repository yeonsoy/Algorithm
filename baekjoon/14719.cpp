#include <iostream>
using namespace std;

// 빗물

int H, W;
int map[501][501];
int answer;
int main() {
    
    cin >> H >> W;
    
    int num;

    for(int i = 0; i<W; i++) {
        cin >> num;
        
        for(int j = H - 1; j>= H - num; j--)
            map[j][i] = 1;
    }
    
    for(int i = 0; i<H; i++){
        int st = -1;
        int temp = 0;
        for(int j = 0; j<W; j++) {
             if(st == -1)
             {
                 if(map[i][j] == 1)
                     st = j;
             }
             else {
                 if(map[i][j] == 0) temp++;
                 else {
                     answer += temp;
                     temp = 0;
                     st = j;
                 }
             }
        }
    }
    
    cout << answer << endl;
    return 0;
}
