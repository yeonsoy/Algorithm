#include <iostream>
using namespace std;

// 고득점

// 가장 처음 화면 'A'
// 조이스틱을 앞으로 움직이면 알파벳 다음 글자
// 뒤로 움직이면 알파벳 이전 글자
// 왼쪽으로 움직이면 현재의 왼쪽 글자
// 오른쪽으로 움직이면 오른쪽 글자
// M 보다 작으면 A 방향, N 보다 크면 Z 방향

int T;

void getHighScore(string s) {
    
    int answer = 0;
    int length = (int) s.size();
    int move = length - 1; // 기본적으로 오른쪽으로 가야하는 횟수

    for (int i = 0; i < length; i++)
    {
        int pos = i + 1;
        char pivot = s[i];
        if (pivot <= 'N') // 절반 이하이면
            answer += pivot - 'A'; // 앞으로 움직이기
        else
            answer += 'Z' - pivot + 1; // 뒤로 움직이기
        
        while (pos < length && s[pos] == 'A') // 다음 위치의 글자가 A인 경우
            pos++; // 바로 오른쪽으로 움직이기

        // 오른쪽으로 움직일 지 왼쪽으로 움직일 지
        // (i + length - pos) 현재까지 움직인 횟수
        // i 왼쪽으로 움직이기
        // length - pos 오른쪽으로 움직이기
        
        int move2 = (i + length - pos) + min(i, length - pos);
        move = min(move, move2);
    }
    
    answer += move;
    cout << answer << endl;
}

int main() {
    cin >> T;
    
    for(int i = 0; i<T; i++){
        string str;
        cin >> str;
        getHighScore(str);
    }
    
    return 0;
}
