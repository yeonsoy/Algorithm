#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 나무 재테크
// 봄에는 나무가 양분을 먹고 나이가 1증가
// 가장 처음에 양분은 5만큼 들어있다
// 나무는 1x1 칸에 있는 양분만 먹을 수 있음
// 하나의 칸에 여러 나무가 있다면 나이가 어린 나무부터 양분을 먹음
// 땅에 양분이 부족해서 자신의 나이만큼 양분을 먹을 수 없으면 죽음
// 여름에는 봄에 죽은 나무가 양분이 됨. 죽은 나무의 나이/2 가 양분이 됨 (소수점 이하는 버림)
// 가을에는 나무가 번식한다 (번식하는 나무는 나이가 5의 배수)
// 인접한 8개의 칸에 나이가 1인 나무가 생긴다

typedef pair<int, int> point;

int N, M, K;
int A[11][11]; // 기본 양분
int S2D2[11][11]; // S2D2가 추가하는 양분

vector <int> trees[11][11]; // 배열 정보는 나무의 위치, 값은 나무의 나이
point dir[8] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0} };

void springsummer()
{

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			if (trees[r][c].size() == 0)
				continue;

			sort(trees[r][c].begin(), trees[r][c].end()); // 나이가 어린 나무부터 양분을 먹음

			vector<int>trees_temp;
			int dead_tree = 0;

			for (int i = 0; i < trees[r][c].size(); i++)
			{
				if (A[r][c] >= trees[r][c][i])
				{
					A[r][c] -= trees[r][c][i];
					trees_temp.push_back(trees[r][c][i] + 1);
				}
				else // 나무가 죽음 (양분이 남아있지 않음) 죽은 나무들 새로운 양분으로 변환
					dead_tree += trees[r][c][i] / 2;
			}

			trees[r][c].clear();

			for (int i = 0; i < trees_temp.size(); i++)
				trees[r][c].push_back(trees_temp[i]);

			A[r][c] += dead_tree;
		}
}

void autumn()
{
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			if (trees[r][c].size() == 0)
				continue;

			for (int i = 0; i < trees[r][c].size(); i++)
			{
				if (trees[r][c][i] % 5 == 0) // 만약 나무의 나이가 5의 배수이면
				{
					for (int k = 0; k < 8; k++)
					{
						int row = r + dir[k].first;
						int column = c + dir[k].second;

						if (row <= 0 || row > N)
							continue;

						if (column <= 0 || column > N)
							continue;

						trees[row][column].push_back(1); // 나무 번식
					}
				}
			}

		}
}

void winter() // 겨울엔 S2D2가 양분을 추가함
{
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			A[r][c] += S2D2[r][c];
}


void tree(int year)
{
	for (int i = 0; i < year; i++)
	{
		springsummer();
		autumn();
		winter();
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			cin >> S2D2[r][c];
			A[r][c] = 5;
		}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	tree(K);

	int answer = 0;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			answer += trees[r][c].size();

	cout << answer << endl;

	return 0;
}