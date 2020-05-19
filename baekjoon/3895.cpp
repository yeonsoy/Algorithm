#include <iostream>
#include <vector>
using namespace std;

// 그리고 하나가 남았다

int n, k, m;
vector <int> number;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true) {
        cin >> n >> k >> m;
        if(n == 0 && k == 0 && m == 0) break;
        
        k--; m--;
        
        for(int i = 0; i<n; i++)
            number.push_back(i + 1);
        
        while(true) {
            number.erase(number.begin() + m);
            m += k;
            
            if(m >= number.size())
                m %= number.size();
            
            if(number.size() == 1) break;
        }
        
        cout << number[0] << endl;
        number.clear();
        
    }
    
    return 0;
}
