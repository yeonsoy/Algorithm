#include <iostream>
#include <algorithm>
using namespace std;

// 팰린드롬 만들기

string name;
int alphabet[26];
char mid = '0';
bool isPossible() {
    
    for(int i = 0; i<name.size(); i++)
        alphabet[name[i] - 'A']++;
    
    int flag = 0;
    for(int i = 0; i<26; i++) {
        if(alphabet[i] % 2 == 1) { // 홀수개의 문자열이 있다면
            flag++; // 개수 카운트
            mid = i + 'A'; // 해당 문자 저장
        }
        if(flag > 1) return false;
    }
    
    return true;
}

int main() {
    
    cin >> name;
    
    sort(name.begin(), name.end());
    
    if(isPossible()) {
        string answer = "";
        for(int i = 0; i<26; i++) {
            for(int j = 0; j<alphabet[i]/2; j++)
                answer += i + 'A';
        }
        
        cout << answer;
        if(mid != '0')
            cout << mid;
        reverse(answer.begin(), answer.end());
        cout << answer;
    }
    else cout << "I'm Sorry Hansoo";
    
    return 0;
}
