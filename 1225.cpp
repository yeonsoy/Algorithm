#include <iostream>
#include <queue>
using namespace std;
 
// 암호생성기

queue <int> password;
int N;
 
int main()
{
    for(int test_case = 0; test_case < 10; test_case++) {
    cin >> N;
     
    for(int i = 0; i<8; i++) {
        int num;
        cin >> num;
        password.push(num);
    }
     
           bool flag = true;
    while(flag) {
  
        for(int i =1; i<=5; i++) {
            int front = password.front();
            password.pop();
             
            front -= i;
            if(front <= 0) {
                password.push(0);
                flag = false;
                break;
            }
            password.push(front);
        }
    }
     
        cout << "#" << N << " ";
    while(!password.empty()) {
        int front = password.front();
                   password.pop();
         
        cout << front << " ";
    }
         
        cout << endl;
    }
     
    return 0;
}
