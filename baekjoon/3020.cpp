#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 개똥벌레

int N, H;
vector <int> up_side, down_side;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> H;
    
    up_side.resize(N / 2);
    down_side.resize(N / 2);
    
    for(int i = 0; i<N/2; i++)
        cin >> down_side[i] >> up_side[i];
    
    sort(up_side.begin(), up_side.end());
    sort(down_side.begin(), down_side.end());
    
    int count = 1;
    int answer = 2e9;
    
    for(int i = 1; i<=H; i++) {
        int up = up_side.size() - (upper_bound(up_side.begin(), up_side.end(), H - i) - up_side.begin());
        int down = down_side.size() - (lower_bound(down_side.begin(), down_side.end(), i) - down_side.begin());
        
        if(answer == up + down)
            count++;
        else if(answer > up + down) {
            answer = up + down;
            count = 1;
        }
        
    }
    
    cout << answer << " " << count << "\n";
    
    return 0;
}
