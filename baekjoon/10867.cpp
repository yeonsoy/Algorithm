#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 중복 빼고 정렬하기

int N;
vector <int> number;

int main()
{
	fastio();

	cin >> N;

	number.resize(N);

	for (int i = 0; i < N; i++)
		cin >> number[i];

	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());

	for (int i = 0; i < number.size(); i++)
		cout << number[i] << " ";

	return 0;
}