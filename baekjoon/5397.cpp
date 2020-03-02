#include <iostream>
#include <list>
#include <string>
using namespace std;

int T;

int main()
{
    cin >> T;
    
    for(int test_case =0; test_case <T; test_case++)
    {
        string str;
        cin >> str;
        list <char> password;
        list <char>::iterator cur = password.begin();
        
        for(int i =0; i<str.size(); i++)
        {
            switch (str[i]) {
                case '<':
                    if(cur != password.begin()) cur --;
                    break;
                case '>':
                    if(cur != password.end()) cur ++;
                    break;
                case '-':
                    if(cur != password.begin()) password.erase((--cur)++);
                    break;
                default:
                    password.insert(cur, str[i]);
                    break;
            }
        }
        
        for(auto p : password)
            cout << p;
        
        cout << endl;
        
    }
    
    return 0;
}
