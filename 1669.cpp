#include <iostream>
#include <math.h>
using namespace std;

int X, Y;
int answer;

// 멍멍이 쓰다듬기

int main() {
    
    cin >> X >> Y;
    
    int diff = Y - X;
    
    if(diff < 1) {
        answer = 0;
    }
    else {
        int d = sqrt(diff);
        
        if(d * d < diff)
            d++;
        
        if(d * d - d < diff)
            answer = d * 2 - 1;
        else
            answer = d * 2 - 2;
    }
    
    cout << answer << endl;
    
    return 0;
}
