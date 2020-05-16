#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 규영이와 인영이의 카드게임

int T;
int isUsed[19];
int origin[9];
int win_count, lose_count;

void solve(int count, int i_sum, int k_sum) {
    
    if (i_sum > (171 / 2) || k_sum > (171 / 2))
    {
        int result = 1;
        for (int i = 9 - count; i >= 1; i--)
            result *= i;
        
        if(k_sum > i_sum)
            win_count += result;
        else if(k_sum < i_sum)
            lose_count += result;
        
        return;
    }
    
    if(count >= 9) {
        
        if(k_sum > i_sum)
            win_count++;
        else if(k_sum < i_sum)
            lose_count++;
        
        return;
    }
    
    for(int i = 1; i<=18; i++) {
        if(isUsed[i] == 0) {
            isUsed[i] = 2;
            
            int i_sum_temp = i_sum;
            int k_sum_temp = k_sum;
            
            if(i > origin[count])
                i_sum_temp += i + origin[count];
            else
                k_sum_temp += i + origin[count];
            
            solve(count + 1, i_sum_temp, k_sum_temp);
            
            isUsed[i] = 0;
        }
    }
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        
        memset(isUsed, 0, sizeof(isUsed));
        int num;
        for(int i = 0; i<9; i++)
        {
            cin >> num;
            isUsed[num] = 1;
            origin[i] = num;
        }
        
        solve(0, 0, 0);
        
        cout << "#" << test_case + 1 << " " << win_count << " " << lose_count << endl;
        
        win_count = 0;
        lose_count = 0;
    }
    
    return 0;
}
