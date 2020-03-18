#include <iostream>
#include <vector>
using namespace std;

vector <string> lines;

int main() {
    
    string line;
    int length = 0;
    bool newline = true;
    
    while (cin >> line)
    {
        if (line == "<br>")
        {
            cout << endl;
            length = 0;
        }
        else if (line == "<hr>")
        {
            if (length != 0) // 새로운 줄이 아니라면
                cout << endl;
            
            for (int i = 0; i < 80; i++)
                cout << "-";
            
            cout << endl;
            
            length = 0;
        }
        else
            if (length == 0)
            {
                length = line.length();
                cout << line; // 새로운 줄이라면
                newline = false; // 다음 단어는 이어지도록
            }
            else if (length + line.length() + 1 <= 80) // 현재 단어까지 80글자 이하인 경우
            {
                if (!newline)
                {
                    cout << " ";
                    length += 1;
                }
                
                length += line.length();
                cout << line;
                
                if (length == 80) // 띄어쓰기 이후에 80글자가 된 경우
                {
                    cout << endl;
                    length = 0;
                    newline = true;
                }
            }
            else // 글자가 80 초과라면
            {
                cout << endl << line;
                length = line.size();
                newline = false;
            }
        
    }
    
    return 0;
}
