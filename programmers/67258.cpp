#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 보석 쇼핑

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.resize(2);
    
    set<string> s(gems.begin(), gems.end());
    map<string, int> m;
    
    int st = 0, ed = 0;
    int jewel = (int) s.size();
    m[gems[0]]++;
    int count = 1;
    
    answer[0] = 1;
    answer[1] = gems.size();
    
    while(st <= ed) {
        
        // 보석이 다 찾아지지 않았으면
        if(count < jewel && ed != gems.size() - 1) {
            ed++;
            // 범위 갱신 후 새로운 보석 발견
            if(m[gems[ed]] == 0) count++;
            m[gems[ed]]++;
        }
        
        // 보석을 다 찾았다면
        else if(count == jewel) {
            
            // 현재 경로보다 더 짧은 경로인 경우에 갱신
            if(ed - st < answer[1] - answer[0]) {
                answer[0] = st + 1;
                answer[1] = ed + 1;
            }
            
            // 범위 갱신 후 보석 갱신
            if(m[gems[st]] == 1) count--;
            m[gems[st]]--;
            st++;
        }
        else break;
    }
    
    return answer;
}
