#include <iostream>
using namespace std;
 
// String

int main(int argc, char** argv)
{
    for(int i = 0; i<10; i++)
    {
        int n = 0;
        int answer = 0;
        string search, str;
        cin >> n >> search >> str;
 
        for (int i = 0; str[i]; i++)
        {
            if (i + search.length() <= str.length())
                if (str.substr(i, search.length()) == search)
                    answer++;
        }
 
        cout << "#" << n << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
