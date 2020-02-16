#include <iostream>
#include <vector>
using namespace std;

// 배열 돌리기 4

int N, M, K;
int A[51][51];
bool isUsed[6];
int answer = 987654321;

struct rotateInfo {
    int r;
    int c;
    int s;
};

vector <rotateInfo> info;

void cpyArray(int a[51][51], int b[51][51])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            b[i][j] = a[i][j];
}


void rotateArray(int r, int c, int s, int arr[51][51])
{
    while (s > 0) {
        
        int tmp = arr[r - s][c - s];
        
        //첫번째 열 이동
        for (int i = r - s; i < r + s; i++) {
            arr[i][c - s] = arr[i + 1][c - s];
        }
        
        //마지막 행 이동
        for (int j = c - s; j < c + s; j++) {
            arr[r + s][j] = arr[r + s][j + 1];
        }
        
        //마지막 열 이동
        for (int i = r + s; i > r - s; i--) {
            arr[i][c + s] = arr[i - 1][c + s];
        }
        
        //첫번째 행 이동
        for (int j = c + s; j > c - s + 1; j--) {
            arr[r - s][j] = arr[r - s][j - 1];
        }
        
        //마지막 칸
        arr[r - s][c - s + 1] = tmp;
        s--;
    }
}

void calc(int arr[51][51]) {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += arr[i][j];
        }
        answer = (answer > sum) ? sum : answer;
    }
}

void solve(int index, int arr[51][51]) {
    if (index == K) {
        calc(arr);
        return;
    }
    
    for (int i = 0; i < K; i++) {
        //i번을 이미 사용
        if (!isUsed[i]) {
            
            int newArray[51][51];
            cpyArray(arr, newArray);
            isUsed[i] = true;
            rotateArray(info[i].r, info[i].c, info[i].s, newArray);
            solve(index + 1, newArray);
            isUsed[i] = false;
        }
        
    }
    
}

int main()
{
    cin >> N >> M;
    cin >> K;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        info.push_back({ r - 1, c - 1, s });
    }
    
    
    solve(0, A);
    
    cout << answer << endl;
    
    return 0;
}
