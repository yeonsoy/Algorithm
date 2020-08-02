#include <iostream>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// Flatten

int data[100];
int N;
int answer;

int main() {
    
    for(int test_case = 0; test_case < 10; test_case++) {
        
        cin >> N;
        for(int i = 0; i<100; i++)
            cin >> data[i];
        
        for(int i = 0; i<N; i++) {
            sort(data, data + 100);
            int diff = abs(data[99] - data[0]);
            if(diff == 0 || diff == 1) break;
            data[99]--;
            data[0]++;
        }
        
        sort(data, data + 100);
        answer = abs(data[99] - data[0]);
        
        cout << "#" << test_case + 1 << " " << answer << endl;
    }
    
    return 0;
}
