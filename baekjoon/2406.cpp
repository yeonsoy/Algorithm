#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 안정적인 네트워크
// 1,2번 연결 + 1,3번 연결 = 2,3번도 서로 이동 가능

typedef pair<pair<int, int>, int> network;

int n, m;
int X;
long long K;
vector <network> node;
vector <pair<int, int>> answer;

int parent[1001];
int cost[1001][1001];

int Find(int n) {
    if(parent[n] == n) return n;
    
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parent[b] = a;
}

bool compare(network a, network b) {
    return a.second < b.second;
}

int main() {
    
    cin >> n >> m;
    
    for(int i = 1; i<=n; i++)
        parent[i] = i;
    
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    
    for(int i = 1; i<=n; i++)
        for(int j =1; j<=n; j++)
            cin >> cost[i][j];
    
    for(int i = 2; i<=n; i++)
        for(int j = i+1; j<=n; j++)
            node.push_back({{i, j}, cost[i][j]});
    
    sort(node.begin(), node.end(), compare);
    
    int a, b;
    for(int i = 0; i<node.size(); i++) {
        a = Find(node[i].first.first);
        b = Find(node[i].first.second);
        
        if(a == b) continue;
        
        parent[b] = a;
        K += node[i].second;
        answer.push_back({node[i].first.first, node[i].first.second});
    }
    
    X = answer.size();
    cout << K << " " << X << endl;
  
    for(int i = 0; i<X; i++)
        cout << answer[i].first << " " << answer[i].second << endl;
    
    return 0;
}
