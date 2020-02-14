#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 최소 스패닝 트리
typedef pair<int, int> point;
int V, E;
vector <pair<int, point>> edge;
vector <int> tree;
int parent[10002];

int find_parent(int n)
{
    if(parent[n] == n)
        return n;
    
    return find_parent(parent[n]);
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
    
    cin >> V >> E;
    
    for(int i =0; i<E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edge.push_back({C, {A, B}});
    }
    
    sort(edge.begin(), edge.end());
    
    for(int i = 1; i<=V; i++) parent[i] = i;
    
    for(int i =0; i<E; i++) {
        if(!same_parent(edge[i].second)) {
            Union(edge[i].second);
            tree.push_back(edge[i].first);
        }
    }
    
    int answer = 0;
    for(int i = 0; i<tree.size(); i++)
        answer += tree[i];
    
    cout << answer << endl;
    
    return 0;
}
