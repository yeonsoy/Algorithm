#include <iostream>
#include <vector>
using namespace std;

// 막대기

vector <int> line;

int main()
{
    int X;
    int answer = 0;
    cin >> X;
    
    for(int i = 64; i > 0; i--)
    {
        if(64 % i == 0)
            line.push_back(i);
    }
    
    for(int i =0; i< line.size(); i++)
    {
        if(line[i] <= X)
        {
            X -= line[i];
            answer++;
        }
    }
    
    cout << answer;
    
}
