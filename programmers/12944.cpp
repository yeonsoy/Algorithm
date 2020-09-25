#include <string>
#include <vector>
using namespace std;

// 평균 구하기

double solution(vector<int> arr) {
    double answer = 0;
    int sum = 0;
    
    for(int i =0; i<arr.size(); i++)
        sum += arr[i];
    
    answer = (double) sum / arr.size();
    return answer;
}
