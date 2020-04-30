#include <iostream>
using namespace std;

string str;
int answer;

// 문자열 접기

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;

    for(int i = 0; str[i]; i++) {
        int temp = 1;
        int idx = i;
        char pivot = str[i];
        
        for(int k = i + 1; str[k]; k++)
            if((k - idx) % 2 == 1 && str[k] == pivot) {
                temp++;
                idx = k;
            }
        
        answer = max(temp, answer);
    }
    
    cout << answer << endl;
    
    return 0;
}
