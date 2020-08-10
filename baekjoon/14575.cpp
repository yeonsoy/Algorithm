#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 뒤풀이

struct person {
    int L;
    int R;
};

int N, T;
person p[1001];
int st, ed;
int sum_max, sum_min;

bool isPossible(int mid) {
    sum_max = 0;
    sum_min = 0;
    
    for(int i = 0; i<N; i++) {
        if(mid < p[i].L) return false;
        sum_min += p[i].L;
        sum_max += min(mid, p[i].R);
    }
    
    if(sum_min <= T && T <= sum_max) return true;
    else return false;
}

int main() {
    
    cin >> N >> T;
    
    for(int i = 0; i<N; i++) {
        cin >> p[i].L >> p[i].R;
        sum_min += p[i].L;
        sum_max += p[i].R;
        
        st = min(st, p[i].L);
        ed = max(ed, p[i].R);
    }
    
    if(T < sum_min || sum_max < T)
        cout << -1 << endl;
    else {
        while(true) {
            int mid = (st + ed) / 2;
            
            if(st + 1 == ed) break;
            
            if(isPossible(mid))
                ed = mid;
            else
                st = mid;
        }
        
        cout << ed << endl;
    }
    
    return 0;
}
