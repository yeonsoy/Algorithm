#include <iostream>
#include <stack>
using namespace std;

// 제로

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int K;
stack <int> st;

int main() {

    fastio();
    cin >> K;

    int num;
    for (int i = 0; i < K; i++) {
        cin >> num;
        if (num != 0)
            st.push(num);
        else
            st.pop();
    }

    int sum = 0;

    while (!st.empty()) {

        sum += st.top();
        st.pop();
    }

    cout << sum << endl;


    return 0;
}
