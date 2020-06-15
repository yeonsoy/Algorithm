#include <iostream>
#include <map>
using namespace std;

// 생태학

string str;
map <string, double> trees;
long tree_count;

int main() {
    
    // 입력의 끝까지만 실행
    while(!cin.eof()) {
        getline(cin, str);
        
        if(str == "") break;
        trees[str]++;
        tree_count++;
    }
    
    map<string, double>::iterator it;
    
    // 소수점 4자리까지만 출력
    cout << fixed;
    cout.precision(4);
    
    for(it = trees.begin(); it != trees.end(); it++)
        cout << it->first << " " << ((it->second) / tree_count) * 100 << endl;
    
    return 0;
}
