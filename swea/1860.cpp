#include <iostream>
#include <cstring>
using namespace std;

int T;
int N, M, K;
int order[11112];

// 진기의 최고급 붕어빵

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> N >> M >> K;
        
        memset(order, 0, sizeof(order));
        
        int bread = 0;
        bool flag = true;
        // M초의 시간에 K개의 붕어빵
         int temp;
        for(int i = 0; i<N; i++) {
           
            scanf("%d", &temp);
            order[temp]++;
        }
        
        for(int i = 1; i<11112; i++) {
            
            if(i % M == 0)
                bread+=K;
            
            if(order[i] > 0)
            {
                bread -= order[i];
                if(bread < 0) {
                    flag = false;
                    break;
                }
            }
        }
        
        if(order[0] > 0 && M != 0)
            cout << "#" << test_case + 1 << " Impossible" << endl;
        else if(order[0] > 0 && M == 0)  cout << "#" << test_case + 1 << " Possible" << endl;
        else {
            if(flag)
                cout << "#" << test_case + 1 << " Possible" << endl;
            else
                cout << "#" << test_case + 1 << " Impossible" << endl;
        }
   
    }
    
    return 0;
}
