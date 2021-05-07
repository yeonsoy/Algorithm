#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 디지털 티비
// KBS1을 첫 번째, KBS2를 두 번째.
// 1 화살표 아래 i > i+1
// 2 화살표 위 i > i-1
// 3 현재 채널 아래 (채널 i <-> 채널 i+1) (화살표 i+1)
// 4 현재 채널 위 (채널 i <-> 채널 i-1) (화살표 i-1)

void swap(string a, string b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int N;
	string target[2] = { "KBS1", "KBS2" };
	cin >> N;

	vector <string> channel;
	for (int i = 0; i < N; i++)
	{
		string ch;
		cin >> ch;
		channel.push_back(ch);
	}

	int dir = 0;

	for (int i = 0; i < 2; i++)
	{
		if (channel[i] != target[i]) // 채널 순서가 원하는 순서와 같지 않으면
		{
			if (dir == 0 && i > 0) // 2번째 채널을 구할 때 첫 화살표 위치라면
			{
				cout << 1;
				dir++;
			}

			while (channel[dir] != target[i]) // 목표 채널이 나올 때까지 앞으로 순서바꾸며 화살표 이동
			{
				swap(channel[dir++], channel[dir]);
				cout << 3;
			}

			if (dir != i + 1) // 만약 현재 화살표가 원하는 순서가 아니라면 (목표 채널을 발견하고, 한칸 올린 상태일 때 목표 채널의 위치가 원하는 위치가 아니라면)
			{
				cout << 2;
				dir--;

				while (dir > i) {
					swap(channel[dir], channel[dir - 1]);
					dir--;
					cout << 4; // 뒤로 순서 바꾸며 화살표 이동
				}
			}
		}
	}

	return 0;
}
