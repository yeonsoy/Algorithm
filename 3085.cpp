#include <iostream>
#include <vector>
using namespace std;

// 사탕 게임

int N;
vector <string> board;
int answer;

void getCount()
{
    for(int i =0; i<N; i++)
    {
        int h_temp = 1, v_temp = 1;
        
        for(int j =1; j<N; j++)
        {
            if(board[i][j - 1] == board[i][j])
                h_temp ++;
            else {
                answer = max(h_temp, answer);
                h_temp = 1;
            }
            
            if(board[j-1][i] == board[j][i])
                v_temp++;
            else {
                answer = max(v_temp, answer);
                v_temp = 1;
            }
        }
        
        if(h_temp == N || v_temp == N)
        {
            cout << N << endl;
            exit(0);
        }
        
        answer = max(h_temp, answer);
        answer = max(v_temp, answer);
    }
}

int main()
{
    cin >> N;
    
    for(int i =0; i<N; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    
    for(int i =0; i<N; i++)
        for(int j =0; j<N - 1; j++)
        {
            swap(board[i][j], board[i][j+1]);
            getCount();
            swap(board[i][j+1], board[i][j]);
            
            swap(board[j][i], board[j+1][i]);
            getCount();
            swap(board[j+1][i], board[j][i]);
        }
    
    cout << answer << endl;
    
    return 0;
}
