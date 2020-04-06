#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 큰 수 구성하기

int N, M;
bool numbers[10];
vector <int> unit;
vector <int> K;
vector <int> answer;

bool isPossible(int n) {
    
    int num = n;
    while(num) {
        int temp = num % 10;
        num /= 10;
        if(numbers[temp]) continue;
        else return false;
    }
    
    return true;
}

int solve(int n) {
    
    for(int i = N; i>=K[0]; i--) {
        if(isPossible(i))
            return i;
    }
    
    return 0;
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<M; i++)
    {
        int num;
        cin >> num;
        numbers[num] = true;
        K.push_back(num);
    }
    
    sort(K.begin(), K.end());
    
    cout << solve(N);
    
    return 0;
}
