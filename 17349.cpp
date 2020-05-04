#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

// 1루수가 누구야

int input[9][2];
int check[10];
int answer;

int main() {
    
    for(int i =0; i<9; i++)
        cin >> input[i][0] >> input[i][1];
    
    answer = -1;
    
    for(int i = 0; i < 9; i++) {
        
        // i번째가 거짓말
        if(i > 0) input[i - 1][0] = (input[i - 1][0] == 0) ? 1 : 0;
        input[i][0] = (input[i][0] == 0) ? 1 : 0;
        
        memset(check, -1, sizeof(check));
        
        bool flag = false;
        for(int j = 0; j < 9; j++) {
            // j번째 상태가 다른 상태가 모순될 때
            if(check[input[j][1]] != -1 && check[input[j][1]] != input[j][0])
            {
                flag = true;
                break;
            }
            else check[input[j][1]] = input[j][0];
        }
        if(flag) continue;
        
        set <int> first;
        set <int> non_first;
        for (int j = 1; j <= 9; j++) {
            if (check[j] == 1) first.insert(j);
            if (check[j] == -1) non_first.insert(j);
        }
        
        if (first.size() > 1) continue; // 만약 추측되는 1루수의 번호가 2개 이상이라면
        if (first.size() == 1) { // 추측되는 1루수의 번호가 하나라면
            if (answer != -1) { // 이미 추측한 1루수 번호가 있었다면
                answer = -1;
                break;
            }
            answer = *first.begin();
        }
        else if (non_first.size() == 1)
        {
            if (answer != -1) {
                answer = -1;
                break;
            }
            answer = *non_first.begin();
        }
        else if (non_first.size() == 0)
            continue;
        else {
            answer = -1;
            break;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
