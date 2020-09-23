#include <string>
#include <vector>
using namespace std;

// 풍선 터트리기

int solution(vector<int> a) {
    int answer = a.size();

    // 양 옆의 풍선은 항상 터트릴 수 있다
    if(answer >=0 && answer <= 2)
        return answer;
    
    vector <int> check(a.size(), 0);
    int left = 1;
    int right = a.size() - 1;
    
    for(int i = 1; i<a.size(); i++)
    {
        // 왼쪽부터 더 작은 것 고르기
        if(a[left] > a[i - 1])
            left = i - 1;
        
        // 고른 작은 숫자가 오른쪽에 있는 수보다 작다면
        // 인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있으므로 터뜨린다
        if(a[left] < a[i])
            check[i]++;
    }
    
    for(int i = a.size() - 2; i>=0 ; i--)
    {
        // 오른쪽부터 더 작은 것 고르기
        if(a[right] > a[i + 1])
            right = i + 1;
        
        if(a[right] < a[i])
            check[i]++;
        
        // 고른 작은 숫자가 왼쪽에 있는 수보다 작다면
        // 인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있으므로 터뜨린다
        if(check[i] == 2)
            answer--;
    }
    
    return answer;
}
