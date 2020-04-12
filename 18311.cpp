#include <iostream>
#include <vector>
using namespace std;

// 왕복

long long N, K;
vector <pair<long long, long long>> course;

int main() {
    
    cin >> N >> K;
    
    long long sum = 0;
    for(int i = 0; i<N; i++) {
        long long dist;
        
        cin >> dist;
        if(i < N - 1)
            course.push_back({sum, sum + dist - 1});
        else
            course.push_back({sum, sum + dist});
        
        sum += dist;
    }
    
    if(K > sum)
        K = sum - (K % sum);
    
    for(int i = 0; i<course.size(); i++)
        if(K >= course[i].first && K <= course[i].second)
            cout << i + 1 << endl;
    
    return 0;
}
