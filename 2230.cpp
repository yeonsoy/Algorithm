#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수 고르기

long long N, M;
long long answer = 2e9;
vector <long long> numbers;
int main() {
    
    cin >> N >> M;
    
    numbers.resize(N);
    
    for(int i = 0; i<N; i++)
        cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end());
    
    for(int i = 0; i<N; i++) {
        bool flag = false;
        for(int j = i + 1; j<N; j++)
        {
            long long temp = numbers[j] - numbers[i];
            if(temp >= M) {
                answer = min(temp, answer);
                if(answer == M) flag = true;
                break;
            }
        }
        
        if(flag) break;
    }
    
    cout << answer << endl;
    
    return 0;
}
