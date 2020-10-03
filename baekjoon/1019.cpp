#include <iostream>
#include <vector>
using namespace std;

// 책 페이지

long long N;
long long number[10];

void solve(long long n, long long d) {
    for(long long i = n; i > 0; i /= 10)
        number[i % 10] += d;
}

int main() {
    
    cin >> N;
    
    long long st = 1, ed = N;
    long long idx = 1;
    
    while(st <= ed) {
        
        while(st % 10 != 0 && st <= ed)
            solve(st++, idx);
        
        if(st > ed) break;
        
        while(ed % 10 != 9 && st <= ed)
            solve(ed--, idx);
        
        // 10의 자리 수 차이
        long long check = (ed / 10) - (st / 10) + 1;
        
        for(int i = 0; i<10; i++)
            number[i] += check * idx;
        
        st /= 10;
        ed /= 10;
        idx *= 10;
    }
    
    
    for(int i = 0; i<10; i++)
        cout << number[i] << " ";
    
    return 0;
}
