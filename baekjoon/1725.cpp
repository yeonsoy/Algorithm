#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 히스토그램

int N;
stack<int> st;
int answer;
vector <int> hist;

int main() {
    
    cin >> N;
    
    hist.resize(N + 2);
    for(int i = 1; i <= N; i++)
        cin >> hist[i];
    
    st.push(0);
    
    for(int i = 1; i <= N + 1; i++) {
        
        while(!st.empty() && hist[st.top()] > hist[i]) {
            int height = hist[st.top()];
            st.pop();
            
            int width = i - st.top() - 1;
            
            answer = max(answer, width * height);
        }
        st.push(i);
        
    }
    
    cout << answer << endl;
    
    return 0;
}
