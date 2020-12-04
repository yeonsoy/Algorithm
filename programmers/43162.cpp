#include <string>
#include <vector>
using namespace std;

// 네트워크

bool visited[201];

void dfs(vector<vector<int>>& adj, int n, int idx) {
    for (int i = 0; i < n; i++)
        if (adj[idx][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(adj, n, i);
        }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            visited[i] = true;
            dfs(computers, n, i);
            answer++;
        }

    return answer;
}