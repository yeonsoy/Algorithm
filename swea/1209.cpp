#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// Sum

const int size = 100;
int case_num = 0;
int arr[size][size];

int main() {
    
    fastio();
    
    for(int test_case = 0; test_case < 10; test_case ++) {
        int answer = 0;
        int temp = 0;
        cin >> case_num;
        for(int i = 0; i<size; i++)
            for(int j = 0; j<size; j++)
                cin >> arr[i][j];
        
        for(int i = 0; i<size; i++) {
            temp = 0;
            for(int j = 0; j<size; j++)
                temp += arr[i][j];
            
            answer = max(answer, temp);
        }

        for(int i = 0; i<size; i++) {
            temp = 0;
            for(int j = 0; j<size; j++)
                temp += arr[j][i];
            
            answer = max(answer, temp);
        }
        
        temp = 0;
        for(int i = 0; i<size; i++) {
            temp += arr[i][i];
        }
        
        answer = max(answer, temp);
        
        temp = 0;
        for(int i = 0; i<size; i++)
            temp += arr[i][size - i - 1];
        
        answer = max(answer, temp);
        
        cout << "#" << case_num << " " << answer << endl;
        
    }
    
    return 0;
}
