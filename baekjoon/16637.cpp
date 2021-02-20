#include <iostream>
#include <string>

using namespace std;

/*
	괄호 추가하기
	길이가 N인 수식
	숫자는 모두 1의 자리 수
	+ - * 만 존재.
	* 영역을 가장 크게 만들어야 한다.
	곱하기는 내버려 두고 덧셈은 전부 먼저 더한다.
	-가 있는 경우에만 빠르게 계산한다.

	식은 최대 19까지. 즉 연산자는 10개까지이다.
	* + 의 경우 +를 먼저 계산
	+ * 의 경우 +를 먼저 계산
	- *나 * -의 경우 앞이나 뒤의 수식을 -했을 때의 값이 더 큰 경우에 먼저 진행. 아닌 경우엔 뒤에 진행
	백트래킹? 일단 DFS 같다
*/

int answer = -987654321;
string ep;
int n;

int calc(int a, int b, char oper)
{
	switch (oper)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	default:
		return 0;
		break;
	}
}

void solve(int idx, int ans)
{
	if (idx > n - 2) // 마지막 연산자까지 실행
	{
		answer = (answer < ans) ? ans : answer;
		return;
	}

	int cur = calc(ans, ep[idx + 1] - '0', ep[idx]);
	solve(idx + 2, cur); // 다음 연산자 탐색

	if (idx + 2 <= n - 1) // 다음 연산자 위치가 전체 식 길이를 넘지 않는다면
	{
		int next = calc(ep[idx + 1] - '0', ep[idx + 3] - '0', ep[idx + 2]); // A + B + C라고 한다면 B, C, + 삽입
		int cur = calc(ans, next, ep[idx]);
		solve(idx + 4, cur);
	}

}

int main()
{
	cin >> n >> ep;

	if (n == 1)
		cout << (ep[0] - '0');
	else if (n == 3)
		cout << calc(ep[0] - '0', ep[2] - '0', ep[1]);
	else
	{
		solve(1, ep[0] - '0');
		cout << answer;
	}

	return 0;
}
