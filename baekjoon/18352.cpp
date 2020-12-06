#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 특정 거리의 도시 찾기

int N, M;
int K, X;
vector <int> answer;
vector<vector<int>> graph;
vector<int> visited;

void solve(int n) {

    queue <int> que;
    que.push(n);
    visited[n] = 0;

    while (!que.empty()) {
        int front = que.front();
        que.pop();

        if (visited[front] == K)
            answer.push_back(front);

        for (int i = 0; i < graph[front].size(); i++) {
            if (visited[graph[front][i]] == -1) {
                visited[graph[front][i]] = visited[front] + 1;

                que.push(graph[front][i]);
            }
        }
    }
}

int main() {

    cin >> N >> M >> K >> X;
    graph.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
        visited[i] = -1;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    solve(X);

    if (answer.size() > 0) {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << endl;
    }
    else cout << -1;

    return 0;
}
