#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 팀배분

int n;
bool student[101][101];
int isUsed[101];

void solve() {
    
    vector <int> white;
    vector <int> blue;
    
    queue<int> que;
    vector<int> A, B;
    
    for (int i = 1; i <= n; i++)
    {
        if (isUsed[i] != 0) continue;
        isUsed[i] = 1;
        que.push(i);
        
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            for (int j = 1; j <= n; j++)
            {
                if (isUsed[j] != 0) continue;
                if (student[cur][j]) // 싫어하는 학생이면
                {
                    isUsed[j] = isUsed[cur] * (-1);
                    que.push(j);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (isUsed[i] == 1) blue.push_back(i);
        else if (isUsed[i] == -1) white.push_back(i);
    }
    
    printf("%d\n", (int) blue.size());
    for(int i = 0; i<blue.size(); i++)
        printf("%d ", blue[i]);
    
    printf("\n");
    
    printf("%d\n", (int) white.size());
    for(int i = 0; i<white.size(); i++)
        printf("%d ", white[i]);
}

int main() {
    
    scanf("%d", &n);
    
    int person, idx;
    for(int i = 0; i<n; i++) {
        scanf("%d", &person);
        for(int j = 0; j<person; j++) {
            scanf("%d", &idx);
            student[i + 1][idx] = true;
            student[idx][i + 1] = true;
        }
    }
    
    solve();
    
    return 0;
}
