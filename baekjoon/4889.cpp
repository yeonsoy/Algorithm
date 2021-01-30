#include <iostream>
#include <stack>
using namespace std;

// 안정적인 문자열

string str;
stack <char> st;

int makeStableString(string str) {
	if (str.size() == 0)
		return 0;
	else {
		for (int i = 0; i < str.size(); i++) {
			if(st.empty())
				st.push(str[i]);
			else
			{
				if (str[i] == '}' && st.top() == '{') {
					st.pop();
				}
				else
					st.push(str[i]);
			}
		}
	}

	int count = 0;

	while (!st.empty()) {
		char top = st.top();
		st.pop();
		if (top == '{')
		{
			if (st.top() == '{')
			{
				st.pop();
				count++;
			}
			else {
				st.pop();
				count += 2;
			}
		}
		else
		{
			if (st.top() == '}')
			{
				st.pop();
				count++;
			}
			else {
				st.pop();
			}
		}
	}

	return count;
}

int main() {

	int N = 1;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
			if (str[i] == '-')
				return 0;
		
		while(!st.empty())
			st.pop();

		cout << N << ". " << makeStableString(str) << "\n";
		N++;
	}
	return 0;
}