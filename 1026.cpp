#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 보물
int N, S;
vector <int> A;
vector <int> B;

bool compare(int a, int b){
    return a > b;
}

int main () {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
    {
        cin >> S;
        A.push_back(S);
    }
    
    for(int i = 0; i<N; i++)
    {
        cin >> S;
        B.push_back(S);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);
    
    S = 0;
    
    for(int i =0; i<N; i++)
        S += A[i] * B[i];
    
    cout << S;
    
    return 0;
}
