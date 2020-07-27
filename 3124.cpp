#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
// 최소 스패닝 트리

typedef pair<int, int> point;
int T;
int parent[100002];
 
int Find(int n)
{
     return parent[n] = ((parent[n] == n) ? n : Find(parent[n]));
}
 
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
     
    if(a == b) return false;
    parent[a] = b;
    return true;
}
 
int main()
{
    scanf("%d", &T);
     
    for(int test_case = 0; test_case < T; test_case++)
    {
        int V, E;
        scanf("%d %d", &V, &E);
         
        vector<pair<int, point>> edge;
        for(int i = 0; i<E; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edge.push_back({c, {a, b}});
        }
         
        sort(edge.begin(), edge.end());
         
        for(int i = 1; i<=V; i++)
            parent[i] = i;
         
        long long answer = 0LL;
        for(int i = 0; i<E; i++)
            if(Union(edge[i].second.first, edge[i].second.second))
                answer += edge[i].first;
         
        printf("#%d %lld\n", test_case + 1, answer);
    }
    return 0;
}
