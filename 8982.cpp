#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수족관 1
int N, K;
typedef pair<int, int> point;
vector <point> deep; // column, water
vector <int> hole;

int main() {
    
    cin >> N;
    
    int a, b, c, d;
    cin >> a >> b; // (0, 0)
    
    for (int i = 0; i < N/2 - 1; i++)
    {
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++)
            deep.push_back({b, 0});
    }
    cin >> a >> b; // (a, 0)
    
    cin >> K;
    
    for(int i =0; i<K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        hole.push_back(a);
    }
    
    for (int i = 0; i < hole.size(); i++)
        {
            int height = deep[hole[i]].first;
            deep[hole[i]].second = height;

            for (int j = hole[i] - 1; j >= 0; j--) // 왼쪽
            {
                height = min(height, deep[j].first);
                deep[j].second = max(deep[j].second, height);
            }
            
            height = deep[hole[i]].first;

            for (int j = hole[i] + 1; j < deep.size(); j++) // 오른쪽
            {
                height = min(height, deep[j].first);
                deep[j].second = max(deep[j].second, height);
            }
        }
    
    int answer = 0;
    for(int i =0; i<deep.size(); i++)
        answer += deep[i].first - deep[i].second;
    
    cout << answer;
    
    return 0;
}
