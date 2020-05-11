#include <iostream>
using namespace std;

// 마법의 체스판

int n, m;
int k;

int main() {
    
    cin >> n >> m;
    
    cout << n / 2 + m / 2 << endl;
    
    for(int i = 0; i<m; i++)
           for(int j = 0; j<n; j++)
               if(i == 0 && j % 2 == 1) {
                   cout << (j + 1) << " " << (i + 1) << " ";
                   cout << (j + 1) << " " << m << endl;
               }
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(i == 0 && j % 2 == 1) {
                cout << (i + 1) << " " << (j + 1) << " ";
                cout << n << " " << (j + 1) << endl;
            }
    
    return 0;
}
