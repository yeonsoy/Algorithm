#include <iostream>
using namespace std;

int N, M;
int K;
char map[1001][1001];
int jungle[1001][1001];
int ocean[1001][1001];
int ice[1001][1001];

int main()
{
    
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    
    getchar();
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            scanf("%1c", &map[i][j]);
            
            switch (map[i][j]) {
                case 'J':
                    // 왼쪽 위 영역 + 왼쪽 영역 - 두 영역의 겹침 영역 + 1
                    jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1] + 1;
                    ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1];
                    ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1];
                    break;
                case 'O':
                    jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1];
                    ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1] + 1;
                    ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1];
                    break;
                case 'I':
                    jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1];
                    ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1];
                    ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1] + 1;
                    break;
                default:
                    break;
            }
        }
        getchar();
    }
    
    for(int i = 0; i<K; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        // (c, d) - (c, b - 1) - (a - 1, d) + (a - 1, b - 1)
        
        int j_count = jungle[c][d] - jungle[c][b - 1] - jungle[a - 1][d] + jungle[a - 1][b - 1];
        int o_count = ocean[c][d] - ocean[c][b - 1] - ocean[a - 1][d] + ocean[a - 1][b - 1];
        int i_count = ice[c][d] - ice[c][b - 1] - ice[a - 1][d] + ice[a - 1][b - 1];
        
        printf("%d %d %d\n", j_count, o_count, i_count);
    }
    return 0;
}

