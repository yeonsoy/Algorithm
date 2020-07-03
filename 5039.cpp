#include <iostream>
using namespace std;

// 탄산 음료

int e, f, c;

int main() {
    
    cin >> e >> f >> c;
    
    int empty_bottle = e + f;
    int answer = 0;
    
    while(true) {
        
        if(empty_bottle >= c) {
            answer += (empty_bottle / c);
            empty_bottle = (empty_bottle % c) + (empty_bottle / c);
        }
        else break;
        
    }
    cout << answer << endl;

    return 0;
}
