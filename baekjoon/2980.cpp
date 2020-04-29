#include <iostream>
#include <vector>
using namespace std;

// 도로와 신호등

int N, L;

struct traffic {
    int d;
    int r;
    int g;
};

int answer;
vector <traffic> lights;

int main() {
    
    cin >> N >> L;
    
    
    for(int i = 0; i<N; i++) {
        traffic t;
        cin >> t.d >> t.r >> t.g;
        
        lights.push_back(t);
    }
    
    int length = 0;
    int idx = 0;
    int time = 0;
    
    while(true) {
        
        time++;
        length++;
        if(idx < N)
            if(lights[idx].d == length) {
                //time 13일 때 5 5 였다면 2초 남음
                if(time % (lights[idx].r + lights[idx].g) <= lights[idx].r) // 빨간 불이라면
                    time += lights[idx].r - time % (lights[idx].r + lights[idx].g);
                // 남은 빨간불 시간만큼 기다림
                
                idx++;
            }
        
        if(length == L) break;
    }
    
    cout << time << endl;
    
    return 0;
}
