#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> point;

int N, M;
vector <point> graph[1002];
int selected[1002];

// MST 알고리즘.
// 프림

int main() {
    
    cin >> N >> M;
    
    for(int i =0; i<M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    priority_queue <point> que;
    selected[1] = 1;
    for(int i = 0; i<graph[1].size(); i++)
        que.push({-graph[1][i].second, graph[1][i].first}); // second가 가중치이므로 앞 쪽에 넣어서 정렬되도록
    
    int answer = 0;
    point from, to;
    
    while(!que.empty()) {
        
        from = que.top();
        que.pop();
        
        if(selected[from.second]) continue;
        selected[from.second] = 1;
        answer -= from.first;
        
        for(int i = 0; i<graph[from.second].size(); i++) {
            to = graph[from.second][i];
            if(selected[to.first]) continue;
            que.push({-to.second, to.first});
        }
    }
    
    cout << answer;
    
    return 0;
}
