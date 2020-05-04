#include <iostream>
using namespace std;

int N;
string str;
string answer = "뭐야?";

int main() {
    
    cin >> N;
    for(int i = 0; i<N; i++) {
        cin >> str;
        
        if(str == "anj") answer = "뭐야;";
    }
    
    cout << answer << endl;
    
    return 0;
}
