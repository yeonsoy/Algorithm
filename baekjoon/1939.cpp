#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 중량제한
int N, M;
int st, ed;
vector <pair<int, int>> graph[10001];
bool visited[10001];
int answer;

bool bfs(int cost)
{
    queue<int> q;
    visited[st] = true;
    q.push(st);
 
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
 
        if (cur == ed) return true;
 
        for (int i = 0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            if (!visited[next] && cost <= graph[cur][i].second)
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    
    return false;
}

void binarySearch()
{
    int left = 1;
    int right = 1000000000;
 
    while (left <= right)
    {
        int mid = (left + right) / 2;
        memset(visited, false, sizeof(visited));
 
        if (bfs(mid))
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
}

int main() {
    
    cin >> N >> M;
    
    int a, b;
    long long c;
    for(int i = 0; i<M; i++) {
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    cin >> st >> ed;
    
    binarySearch();
    
    cout << answer << endl;
    
    return 0;
}
