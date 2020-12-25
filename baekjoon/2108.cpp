#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 통계학

int N;
long long sum;
vector <int> num;
int cnt[8002];

int main() {
    
    fastio();
    
    cin >> N;
    
    num.resize(N);
    for(int i = 0; i<N; i++) {
        cin >> num[i];
        sum += num[i];
        cnt[num[i] + 4000]++;
    }
    
    sort(num.begin(), num.end());
    cout << round(sum / (float)N) << endl;
    
    cout << num[num.size() / 2] << endl;
    
    int max_count = 0;
    for(int i = 0; i<8002; i++) {
        if(cnt[i] > max_count)
            max_count = cnt[i];
    }
    
    int idx = 0;
    int check = 0;
    for(int i = 0; i<8002; i++) {
        if(max_count == cnt[i]) {
            idx++;
            check = i;
        }
    }
    
    if(idx == 1)
        cout << check - 4000 << endl;
    else {
        idx = 0;
        for(int i = 0; i<8002; i++) {
            if(max_count == cnt[i]) {
                idx++;
                if(idx == 2) {
                    check = i;
                    break;
                }
            }
        }
        cout << check - 4000 << endl;
    }
    
    cout << num[num.size() - 1] - num[0] << endl;

    return 0;
}
