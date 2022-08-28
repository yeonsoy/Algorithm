#include <string>
#include <vector>

using namespace std;

// 없는 숫자 더하기

int solution(vector<int> numbers) {
	int answer = 0;

	for (int i = 1; i <= 9; ++i)
		answer += i;

	for (auto const& number : numbers)
		answer -= number;

	return answer;
}