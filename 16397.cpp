#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 탈출

string answer = "ANG";
int T;
int N, G;
bool isUsed[100000];
queue <int> que;
int result = -1;

bool clickA() {
    int n = que.front();
    if(n >= 99999)
        return true;
    else {
        n++;
        
        if(n == G) return false;
        else if(!isUsed[n])
        {
            que.push(n);
            isUsed[n] = true;
        }
    }
    
    return true;
}

bool clickB() {
    int n = que.front();
    string temp = to_string(n * 2);
    
    if(temp.size() > 5) return true;
    else {
        temp[0]--;
        n = atoi(temp.c_str());
        if(n == G) return false;
        else if(!isUsed[n])
        {
            que.push(n);
            isUsed[n] = true;
        }
    }
    return true;
}

int main() {
    
    fastio();
    
    cin >> N >> T >> G;
    
    que.push(N);
    
    int count = 0;
    
    while(!que.empty()) {
        auto size = que.size();
        bool flag = false;
        
        if(que.front() == G) {
            result = count;
            break;
        }
    
        count++;
        
        while(size--) {
            if(!clickA()) {
                result = count;
                flag = true;
                break;
            }
            if(!clickB()) {
                result = count;
                flag = true;
                break;
            }
            que.pop();
        }
        
        if(flag) break;
        if(count >= T) break;
    }
    
    if(result != -1)
        cout << result << endl;
    else
        cout << answer << endl;
    
    return 0;
}
