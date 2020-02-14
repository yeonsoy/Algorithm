#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

// 도시 분할 계획
// 크루스칼 알고리즘

int N, M;
int answer;
int parent[100001];
vector <pair<int, point>> road;
vector <int> house;

int find_parent(int n) {
    if(n == parent[n]) return n;
    else return parent[n] = find_parent(parent[n]);
}

bool same_parent(point p)
{
    int a = find_parent(p.first);
    int b = find_parent(p.second);
    
    if(a == b) return true;
    return false;
}

void Union(point p, int c) {
    int a = find_parent(p.first);
    int b = find_parent(p.second);
    
    if(a == b) return; // 둘의 부모가 같다면
    parent[b] = a; // 동일한 부모로 만들어주기
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i<M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        road.push_back({C, {A, B}});
    }
    
    sort(road.begin(), road.end());
    
    for(int i = 1; i<=N; i++) parent[i] = i;
    
    for(int i = 0; i<road.size(); i++)
    {
        if(!same_parent(road[i].second)) // 두 점의 부모가 같지 않다면
        {
            Union(road[i].second, road[i].first); // 두 점의 부모를 동일하게 만들어주기
            house.push_back(road[i].first); // 가중치 넣어주기 (새로 만들어준 길 가중치)
        }
    }
    
    for(int i = 0; i<house.size() - 1; i++)
        answer += house[i];
    
    cout << answer << endl;
    
    return 0;
}
