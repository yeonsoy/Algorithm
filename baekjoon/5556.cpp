#include <iostream>
#include <vector>
using namespace std;

// 타일

int N;
int K;

// 빨강 > 파랑 > 노랑
// 1  2  3

int main() {
    
    cin >> N >> K;
    
    for(int i = 0; i<K; i++)
    {
        int r, c;
        cin >> c >> r;
        
        if(r > N / 2)
            r = N - r + 1;
        if(c > N / 2)
            c = N - c + 1;
        
        if(r % 3 == 1) {
            if(r <= c &&  c <= N - r)
                cout << 1;
            else
                cout << ((c % 3 == 0) ? 3 : c % 3);
        }
        if(r % 3 == 2) {
            if(r <= c && c <= N - r)
                cout << 2;
            else
                cout << ((c % 3 == 0) ? 3 : c % 3);
        }
        if(r % 3 == 0) {
            if(r <= c && c <= N - r)
                cout << 3;
            else
                cout << ((c % 3 == 0) ? 3 : c % 3);
        }
        cout << endl;
    }
    
    return 0;
}
