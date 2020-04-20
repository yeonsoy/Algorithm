#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

// 산업 스파이의 편지

int N;
vector<int> number, num_list;
const int MAX = 10000001;
bool era[MAX];
bool isUsed[8];
bool visited[MAX];
int answer;

void solve(int next) {
    if (next > 0) { // 숫자를 한 개 이상 썼을 때
        int num = 0;
        for (int i = 0; i < num_list.size(); i++)
            num += number[num_list[i]] * pow(10, num_list.size() - i - 1);
        
        if (!era[num] && !visited[num]) { // 소수이고 사용한 적 없는 숫자일 때
            visited[num] = true;
            answer++;
        }
    }
    
    for (int i = 0; i < number.size(); i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            num_list.push_back(i);
            solve(next + 1);
            num_list.pop_back();
            isUsed[i] = false;
        }
    }
}

void getEratos() {
    era[0] = era[1] = true;
    for (int i = 2; i < MAX; i++)
        if (era[i] == false)
            for (int j = i + i; j < MAX; j += i) {
                era[j] = true;
            }
}

int main(void) {
    
    cin >> N;
    
    getEratos();
    
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        
        for (int i = 0; i < str.size(); i++)
            number.push_back(str[i] - '0');
        
        solve(0);
        cout << answer << endl;
        memset(isUsed, 0, sizeof(isUsed));
        memset(visited, 0, sizeof(visited));
        number.clear();
        answer = 0;
    }
    
    return 0;
}
