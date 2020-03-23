#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 불필요한 칸이 있지 않고 (가장 왼쪽 위, 가장 오른쪽 아래 칸과 w, h가 일치)
// 상하 좌우로 모두 연결되어 있다 (BFS로 한번에 탐색 가능)

// 회전 없이 가장 왼쪽 위에 부착
// 붙이는 것이 불가능하다면 90도 회전 후 부착

typedef pair <int, int> point;
struct sticker {
    int r, c;
    int map[41][41];
    int count;
};

int N, M, K;
vector <sticker> stk;
int map[41][41];
int answer;

bool isPossible(sticker s, int r, int c, int idx) {
    
    for(int i = r; i<r + s.r; i++)
        for(int j = c; j<c + s.c; j++) {
            
            if(i < 0 || i >= N) return false;
            if(j < 0 || j >= M) return false;
            
            if(map[i][j] == 1 && s.map[i - r][j - c] == 1)
                return false;
        }
    
    return true;
}

void attach(sticker s, int r, int c) {
    
    for(int i = r; i<r + s.r; i++)
        for(int j = c; j<c + s.c; j++) {
            if(s.map[i - r][j - c] == 1)
                map[i][j] = s.map[i - r][j - c];
        }
    
    answer += s.count;
}

void rotate(sticker &s) {
    
    int temp[41][41];
    memset(temp, 0, sizeof(temp));
    
    for(int i = 0; i<s.r; i++)
        for(int j = 0; j<s.c; j++)
            temp[j][s.r - i - 1] = s.map[i][j];
    
    memset(s.map, 0, sizeof(s.map));
    
    swap(s.r, s.c);
    
    for(int i = 0; i<s.r; i++)
        for(int j = 0; j<s.c; j++)
            s.map[i][j] = temp[i][j];
}

void printSticker(sticker &s) {
    for(int i = 0; i<s.r; i++) {
        for(int j = 0; j<s.c; j++) {
            cout << s.map[i][j];
        }
        cout << endl;
    }
}

int main () {
    
    cin >> N >> M >> K;
    
    for(int i = 0; i<K; i++) {
        sticker temp;
        temp.count = 0;
        cin >> temp.r >> temp.c;
        
        for(int j = 0; j<temp.r; j++)
            for(int k = 0; k<temp.c; k++) {
                cin >> temp.map[j][k];
                
                if(temp.map[j][k] == 1)
                    temp.count++;
            }
        stk.push_back(temp);
    }
    
    int idx = 0;
    
    while(idx != K) {
        
        for(int k = 0; k<4; k++)
        {
            bool flag = false;
            for(int i = 0; i<N; i++)
                for(int j =0; j<M; j++) {
                    // 만약 (i,j)부터 현재 스티커를 붙일 수 있다면
                    if(!flag && isPossible(stk[idx], i, j, idx)) {
                        attach(stk[idx], i, j);
                        flag = true;
                        break;
                    }
                }
            if(!flag) rotate(stk[idx]);
            else
                break;
        }
        idx++;
    }
    
    
    cout << answer;
    
    return 0;
}
