#include <iostream>

using namespace std;

int A, B, C, X, Y;

int main()
{
    cin >> A >> B >> C >> X >> Y;
    
    int answer = 0;
    if(C < A/2 + B/2)
    {
        if(X < Y)
        {
            answer = X * C * 2;
            
            if(C * 2 > B)
                answer += (Y - X) * B;
            else
                answer += (Y - X) * C * 2;
        }
        else if(X > Y) {
            answer = Y * C * 2;
            
            if(C * 2 > A)
                answer += (X - Y) * A;
            else
                answer += (X - Y) * C * 2;
        }
        else
            answer = X * C * 2;
        
    }
    else {
        answer = X * A + Y * B;
    }
    
    cout << answer;
    
    return 0;
}
