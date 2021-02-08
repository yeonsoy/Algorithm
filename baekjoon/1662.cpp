#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 압축

int answer;
int position[51];
stack <int> st;
string S;

int getLength(int st, int ed) {
	int res = 0;

	for (int i = st; i < ed; i++) {
		if (S[i] == '(')
		{
			// 괄호 앞에 있는 숫자 * 괄호 내부 숫자 - 1
			res += (S[i - 1] - '0') * getLength(i + 1, position[i]) - 1;
			i = position[i];
			continue;
		}

		res++;
	}

	return res;
}

int main() {

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(')
			st.push(i);
		else if (S[i] == ')')
		{
			position[st.top()] = i;
			st.pop();
		}
	}

	cout << getLength(0, S.size());

	return 0;
}