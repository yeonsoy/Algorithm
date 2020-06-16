#include <iostream>
#include <algorithm>
using namespace std;

// 30

string num;
int number[10];
long long sum;

int main() {
    
    cin >> num;
    
    for(int i = 0; i<num.size(); i++) {
        number[num[i] - '0']++;
        sum += (num[i] - '0');
    }
    
    if(number[0] < 1)
        cout << "-1";
    else {
        if(sum % 3 == 0) {
            sort(num.begin(), num.end());
            reverse(num.begin(), num.end());
            cout << num << endl;
        }
        else cout << "-1";
    }
    
    return 0;
}
