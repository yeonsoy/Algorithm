#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 맥주 마시면서 걸어가기

typedef pair<int, int> point;
int t;
string answer;
point p, temp;
point festival;
vector <point> store;
bool isUsed[101];

int getDiff(point a, point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool canGo(point a, point b) {
    if(getDiff(a, b) / 50.0 <= 20)
        return true;
    else
        return false;
}

int main() {
    
    fastio();
    
    cin >> t;
    
    int n;
    
    for(int test_case = 0; test_case<t; test_case++) {
        
        answer = "sad";
        cin >> n;
        cin >> p.first >> p.second;
        
        for(int i = 0; i<n; i++) {
            cin >> temp.first >> temp.second;
            store.push_back(temp);
        }
        
        cin >> festival.first >> festival.second;
        
        queue <pair<point, int>> que;
        que.push({p, 0});
        
        while(!que.empty()) {
            
            point cur = que.front().first;
            isUsed[que.front().second] = true;
            que.pop();
            
            if(canGo(cur, festival)) {
                answer = "happy";
                break;
            }
            
            for(int i = 0; i<store.size(); i++) {
                
                if(isUsed[i + 1]) continue;
                
                if(canGo(cur, store[i]))
                    que.push({store[i], i + 1});
            }
        }
        
        cout << answer << endl;
        
        store.clear();
        memset(isUsed, false, sizeof(isUsed));
    }
    
    
    return 0;
}
