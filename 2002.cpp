#include <iostream>
#include <queue>
using namespace std;

// 추월

int N;
int answer;
queue <string> que;

int main() {
    
    cin >> N;
    
    string car;
    for(int i = 0; i<N; i++) {
        cin >> car;
        que.push(car);
    }
    
    for(int i = 0; i<N; i++) {
        int size = que.size();
        string front = que.front();
        cin >> car;
        if(front == car)
            que.pop();
        else {
            int idx = 0;
            while(true) {
                front = que.front();
                que.pop();
                
                if(front != car)
                    que.push(front);
                idx++;
                if(idx == size) break;
            }
            
            answer++;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
