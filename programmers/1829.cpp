#include <vector>
#include <queue>
using namespace std;

// 카카오프렌즈 컬러링북

typedef pair<int, int> point;
bool visited[101][101];
point dir[4] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

int indexing(int r, int c, int m, int n, vector<vector<int>>& map) {
	queue <point> que;
	que.push({ r, c });
	visited[r][c] = true;
	int color = map[r][c];
	int area = 1;

	while (!que.empty()) {
		point p = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int rr = p.first + dir[i].first;
			int cc = p.second + dir[i].second;

			if (rr < 0 || rr >= m || cc < 0 || cc >= n)
				continue;

			if (visited[rr][cc]) continue;
			if (map[rr][cc] == color)
			{
				visited[rr][cc] = true;
				que.push({ rr, cc });
				area++;
			}
		}
	}

	return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && picture[i][j] > 0) {
				max_size_of_one_area = max(max_size_of_one_area, indexing(i, j, m, n, picture));
				number_of_area++;
			}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;


	return answer;
}