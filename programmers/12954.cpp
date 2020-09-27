#include <string>
#include <vector>
using namespace std;

// x만큼 간격이 있는 n개의 숫자

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for(int i = 1; i<=n; i++)
        answer.push_back(x * i);

    return answer;
}
