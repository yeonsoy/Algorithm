#include <iostream>

using namespace std;

/*
	야구 (9명)
	N이닝 - 공격과 수비
	3아웃이 발생하면 종료
	두 팀이 공수 변경
	경기 시작 전 타순 결정 완료
	3아웃이 발생하지 않는다면 9번 > 1번
	이닝과 독립적으로 타순 진행
	공격 투수가 던진 공을 타자가 치는 것. 1,2,3루 거쳐 홈에 도착하면 1점 득점
	타자가 공을 쳐서 안타, 2루타, 3루타, 홈런, 아웃
	안타 = 타자와 모든 주자가 한 루
	2루타 = 타자와 모든 주자가 두 루
	3루타 = 타자와 모든 주자가 세 루
	홈런 = 타자와 모든 주자가 홈
	아웃 = 모든 주자는 진루하지 못하고 아웃 증가
*/

int N;
int order[10];
int result[51][10];
int answer;
bool isUsed[10];

void baseball()
{
	int hitter = 1;
	int score = 0;
	int base[10] = { 0 };

	for (int i = 1; i <= N; i++) // i이닝
	{
		int out = 0;

		while (true) {
			if (result[i][order[hitter]] == 0) { // i이닝의 hitter번째 타자가 아웃인 경우
				hitter++;
				if (hitter > 9) hitter = 1; // 9번째 타자 이후 1번째 타자로 수정
				out++;

				if (out == 3) {
					// 이닝 교체
					for (int j = 1; j <= 9; j++) base[j] = 0;
					break;
				}
			}
			else {
				// 안타, 2루타, 홈런
				for (int j = 1; j <= 9; j++) {
					if (base[j] > 0 || j == order[hitter]) { //만약 hitter번째 타자가 진루해 있었다면
						base[j] += result[i][order[hitter]]; // i이닝의 hitter번째 타자가 친 공만큼 진루
						if (base[j] >= 4) {
							// 현재 타자가 홈에 도달하면
							base[j] = 0;
							score++;
						}
					}
				}
				hitter++;
				if (hitter > 9) hitter = 1; // 9번째 타자 이후 1번째 타자로 수정
			}
		}
	}

	answer = (answer < score) ? score : answer;
}

void setHitter(int n)
{
	if (n > 9) // 9번 타자까지 모두 사용하면
	{
		baseball();
		return;
	}

	for (int i = 2; i <= 9; i++) // 1번 선수는 이미 사용했으므로
	{
		if (!isUsed[i]) {
			order[n] = i; // n번 선수를 i번 타자로 결정
			isUsed[i] = true;
			if (n == 3) setHitter(5); // 4번 타자는 이미 정했으므로 5번 타자 결정
			else setHitter(n + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &N);
	isUsed[1] = true;
	order[4] = 1; // 1번 선수를 4번 타자로 결정

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
			scanf("%d", &result[i][j]);
	}

	setHitter(1);

	printf("%d", answer);

	return 0;
}
