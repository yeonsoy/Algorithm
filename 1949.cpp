#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 우수 마을
// N-1개의 길. 마을은 MST이다.

int N;
vector <int> town[10001];
int people[10001];
int isUsed[10001];
int dp1[10001], dp2[10001];

int solve(int n, bool now) {
    
    isUsed[n] = true;
    
    int &sum = now ? dp1[n] : dp2[n];
    // 참조형 변수를 사용하였으므로 dp1[n]이나 dp2[n]의 값도 동시에 업데이트 된다
    if(sum != -1) return sum;
    sum = now ? people[n] : 0;
    
    for(int i =0; i<town[n].size(); i++)
    {
        int next = town[n][i];
        if(!isUsed[next]) {
            if(now) sum += solve(next, false); // 현재 마을을 사용했다면 다음 마을은 사용하지 않는다
            else sum += max(solve(next, true), solve(next, false)); // 현재 마을을 사용하지 않았다면 다음 마을을 사용할지, 안할지 결정한다
        }
    }
    
    isUsed[n] = false;
    return sum;
}

int main() {
    
    scanf("%d", &N);
    
    for(int i =1; i<=N; i++)
        scanf("%d", &people[i]);
    
    for(int i = 0; i<N-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        town[x].push_back(y);
        town[y].push_back(x);
    }
    
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    printf("%d", max(solve(1, true), solve(1, false)));
    
    return 0;
}
