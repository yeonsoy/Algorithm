#include <iostream>
using namespace std;

// 전구와 스위치

int N;
string st;
string ed;
string temp;

int blink(int n) {
    
    temp = st;
    int answer = 0;
    if(n == 1) {
        answer++;
        
        for(int j = -1; j<=1; j++) {
                   if(j < 0 || j>=N) continue;
                   temp[j] = (temp[j] == '0') ? '1' : '0'; // 0번째 스위치 누르기
               }
        
        for(int i = 1; i<N; i++) // 스위치 번호
            if(temp[i-1] != ed[i-1]) {
                for(int j = i - 1; j<=i + 1; j++) {
                    if(j < 0 || j>=N) continue;
                    temp[j] = (temp[j] == '0') ? '1' : '0'; // i번째 스위치 누르기
                }
                
                answer++;
            }
    }
    else {
        for(int i = 1; i<N; i++) // 스위치 번호
            if(temp[i-1] != ed[i-1]) {
                for(int j = i - 1; j<=i + 1; j++) {
                    if(j < 0 || j>=N) continue;
                    temp[j] = (temp[j] == '0') ? '1' : '0'; // i번째 스위치 누르기
                }
                
                answer++;
            }
    }
    
    for(int i = 0; i<N; i++)
        if(temp[i] != ed[i])
            return -1;
    
    return answer;
}

int main() {
    
    cin >> N >> st >> ed;
    
    if(st == ed)
        cout << "0";
    else {
       
        
        int answer = blink(0);
        
        if(answer == - 1)
            answer = (blink(0) != -1) ? min(blink(1), answer) : blink(1);
        
        cout << answer;
    }
    
    return 0;
}
