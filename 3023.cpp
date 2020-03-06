#include <iostream>
using namespace std;

int R, C;
int A, B;
char card[101][101];

int main()
{
    cin >> R >> C;
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            cin >> card[i][j];
    
    cin >> A >> B;
    
    int pivot = 0;
    for(int i = 0; i<R; i++) // 오른쪽
    {
        pivot = C - 1;
        for(int j = C; j<C * 2; j++)
            card[i][j] = card[i][pivot--];
    }
    
    pivot = R - 1;
    for(int i = R; i<R * 2; i++) // 아래
    {
        for(int j = 0; j<C * 2; j++)
            card[i][j] = card[pivot][j];
        pivot--;
    }
    
    card[A - 1][B - 1] = (card[A - 1][B - 1] == '.') ? '#' : '.';
    
    for(int i = 0; i<R * 2; i++) {
        for(int j = 0; j<C * 2; j++)
            cout << card[i][j];
        
        cout << endl;
    }
    return 0;
}
