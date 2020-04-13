#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N;
int r_count, b_count;
int answer = INF;
string str;

int main()
{
    cin >> N;
    cin >> str;
    for(int i = 0; i<N; i++) {
        if(str[i] == 'R') r_count++;
        else b_count++;
    }
    
    // left R
    int now_count = 0;
    int pivot = 0;
    
    while(str[pivot++] == 'R'){ now_count++; }
    answer = min(answer, r_count - now_count);
    
    //right R
    pivot = N - 1;
    now_count = 0;
    
    while(str[pivot--] == 'R'){ now_count++; }
    answer = min(answer, r_count - now_count);
    
    //left B
    pivot = 0;
    now_count = 0;
    
    while(str[pivot++] == 'B'){ now_count++; }
    answer = min(answer, b_count - now_count);
    
    //right B
    pivot = N - 1;
    now_count = 0;
    
    while(str[pivot--] == 'B') { now_count++; }
    answer = min(answer, b_count - now_count);
    
    cout << answer;
    
    return 0;
}
