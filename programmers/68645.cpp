#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define inf 2e9

// 삼각 달팽이

int arr[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    
    int idx = 0;
    int x = 0, y = 0;
    int num = 1;
    
    int total = 0;
    
    // 삼각형 모양으로 배열에 그려두기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++) {
            arr[i][j] = inf;
            total++;
        }
    
    arr[x][y] = num;
    
    while (idx < total){
        
        // 오른쪽 대각선으로 그리기
        while (arr[x + 1][y + 1] == inf) {
            x++; y++;
            arr[x][y] = ++num;
        }
        
        // 밑변에서 왼쪽으로
        while (arr[x][y - 1] == inf){
            y--;
            arr[x][y] = ++num;
        }
        
        // 위쪽으로
        while (arr[x - 1][y] == inf){
            x--;
            arr[x][y] = ++num;
        }
        
        idx++;
    }

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >=0; j--)
            if(arr[i][j] != inf && arr[i][j] != 0)
                answer.push_back(arr[i][j]);
    
    return answer;
}

int main() {
    vector<int> res = solution(5);
    
    for(int i = 0; i<res.size(); i++)
        cout << res[i] << " ";
    
}
