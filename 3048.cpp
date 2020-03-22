#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N1, N2;
int T;
vector <char> A;
vector <char> B;
vector <pair<char, int>> answer;
char ch;

void move() {
    
    vector <int> temp;
    for(int i = 0; i<answer.size() - 1; i++) {
        if(answer[i].second == 1 && answer[i + 1].second == -1)
            temp.push_back(i);
    }
    
    for(int i = 0; i<temp.size(); i++)
        swap(answer[temp[i]], answer[temp[i]+1]);
}

int main() {
    
    cin >> N1 >> N2;
    
    for(int i = 0;i<N1; i++) {
        cin >> ch;
        A.push_back(ch);
    }
    
    for(int i = 0;i<N2; i++) {
           cin >> ch;
           B.push_back(ch);
       }
    
    reverse(A.begin(), A.end());
    
    for(int i = 0; i<A.size(); i++)
        answer.push_back({A[i], 1});
    
    for(int i = 0; i<B.size(); i++)
        answer.push_back({B[i], -1});
    
    cin >> T;
    
    for(int i = 0; i<T; i++)
        move();
    
    for(int i = 0; i<answer.size(); i++)
        cout << answer[i].first;
    cout << endl;
    
    return 0;
}
