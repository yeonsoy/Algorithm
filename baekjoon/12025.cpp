#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 장난꾸러기 영훈

string password;
long long k;
long long n;

int main() {
    
    fastio();
    
    cin >> password >> k;
    n = k - 1;
    
    long long case_count = 1;
    for(int i = 0; i<password.size(); i++) {
        if(password[i] == '1' || password[i] == '2' || password[i] == '6' || password[i] == '7') {
            if(password[i] == '6')
                password[i] = '1';
            else if(password[i] == '7')
                password[i] = '2';
            case_count *= 2;
        }
    }
    
    if(case_count < k || k < 0) cout << -1 << endl;
    
    else {
        for (int i = password.length() - 1; i >= 0; i--)
        {
            if(password[i] == '1' || password[i] == '2' || password[i] == '6' || password[i] == '7')
            {
                if (n % 2 == 1)
                {
                    if(password[i] == '1')
                        password[i] = '6';
                    else if(password[i] == '2')
                        password[i] = '7';
                }
                n /= 2;
            }
        }
        
        cout << password << endl;
    }
    
    return 0;
}
