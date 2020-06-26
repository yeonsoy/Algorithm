#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 행성 연결
typedef pair<int, int> point;
int N;
vector <pair<int, point>> edge;
int map[1001][1001];
int parent[1001];

long long answer;

int find_parent(int n)
{
    if(parent[n] == n)
        return n;
    
    return parent[n] = find_parent(parent[n]);
}

bool same_parent(point p) {
    
    int a = find_parent(p.first);
    int b = find_parent(p.second);
    
    if(a == b) return true;
    else
        return false;
}

void Union(point p) {
    int a = find_parent(p.first);
    int b = find_parent(p.second);
    
    if(a == b) return;
    else
        parent[b] = a;
}

int main() {
    
    fastio();
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> map[i][j];
    
    for(int i = 0; i<N; i++)
        for(int j = i + 1; j<N; j++) {
            int weight = map[i][j];
            edge.push_back({weight, {i, j}});
        }
    
    sort(edge.begin(), edge.end());
    
    for(int i = 1; i<=N; i++)
        parent[i] = i;
    
    for(int i =0; i<edge.size(); i++)
        if(!same_parent(edge[i].second)) {
            answer += edge[i].first;
            Union(edge[i].second);
        }
    
    cout << answer << endl;
    
    return 0;
}
